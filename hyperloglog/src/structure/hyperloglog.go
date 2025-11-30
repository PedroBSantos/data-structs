package structure

import (
	"crypto/md5"
	"fmt"
	"hash"
	"io"
	"math"
	"math/bits"
)

// Contar elementos distintos (cardinalidade) dentro de um conjunto grande de dados usando pouca memória
type HyperLogLog struct {
	firstPBits uint
	hasher     hash.Hash
	registers  []uint
}

func NewHyperLogLog(firstPBits uint) (*HyperLogLog, error) {
	if firstPBits <= 0 || firstPBits > 16 {
		return nil, fmt.Errorf("p must be between 1 and 16")
	}
	registersCount := calculateRegisters(firstPBits)
	hyperLogLog := HyperLogLog{
		firstPBits: firstPBits,
		hasher:     md5.New(),
		registers:  make([]uint, registersCount),
	}
	return &hyperLogLog, nil
}

func calculateRegisters(firstPBits uint) uint {
	registersCount := uint(math.Pow(2, float64(firstPBits)))
	return registersCount
}

func (h *HyperLogLog) Registers() int {
	return len(h.registers)
}

func (h *HyperLogLog) GenerateHash(input string) ([]byte, error) {
	h.hasher.Reset()
	_, err := io.WriteString(h.hasher, input)
	if err != nil {
		return nil, err
	}
	return h.hasher.Sum(nil), nil
}

func (h *HyperLogLog) ExtractFirstPBits(hash []byte) (uint64, []byte, error) {
	if h.firstPBits == 8 {
		firstBits := hash[0] // p = 8, logo o primeiro índice de hash já são os primeiros bits
		return uint64(firstBits), hash[1:], nil
	}
	if h.firstPBits%8 == 0 {
		firstBits := 0
		currentIndex := 0
		for i := 0; i < (int(h.firstPBits) / 8); i++ { // Como cada valor de hash é um inteiro de 8 bits, fazemos h.firstPBits / 8 para descobrir quantas vezes iterar
			firstBits = (firstBits << 8) | int(hash[i]) // Como p é múltiplo de 8, devemos concatenar os bits.
			currentIndex = i
		}
		return uint64(firstBits), hash[currentIndex+1:], nil
	}
	if h.firstPBits < 8 {
		firstBits := hash[0] >> (8 - h.firstPBits) // Os primeiros bits estão em hash[0], mas é preciso deslocar os bits para a direita até restar os p primeiros bits (8 - h.firstPBits)
		rest := (hash[0] << h.firstPBits) >> h.firstPBits
		return uint64(firstBits), append([]byte{rest}, hash[1:]...), nil
	}
	// Caso p > 8. Aqui é uma mistura entre p ser múltiplo de 8 e p < 8. Pegamos todos os bits de hash[0] e depois concatenamos com os primeiros bits de hash[1].
	extraBits := h.firstPBits - 8
	firstBits := 0
	firstBits = (firstBits << 8) | int(hash[0])
	firstBits = (firstBits << int(extraBits)) | int(hash[1])>>(8-int(extraBits))
	rest := (hash[1] << extraBits) >> extraBits
	return uint64(firstBits), append([]byte{rest}, hash[1:]...), nil
}

func (h *HyperLogLog) Add(value string) error {
	valueHash, err := h.GenerateHash(value)
	if err != nil {
		return err
	}
	firstPBits, hashSuffix, err := h.ExtractFirstPBits(valueHash)
	if err != nil {
		return err
	}
	leadingZeros := 0
	for i := range hashSuffix {
		if hashSuffix[i] == 0 {
			leadingZeros += 8
			continue
		}
		leadingZeros += bits.LeadingZeros8(hashSuffix[i])
		break
	}
	rank := leadingZeros + 1
	if rank > int(h.registers[firstPBits]) {
		h.registers[firstPBits] = uint(rank)
	}
	return nil
}

func (h *HyperLogLog) Estimate() float64 {
	m := float64(len(h.registers))
	var alpha float64
	// Definindo os valores α - alpha
	switch len(h.registers) {
	case 16:
		alpha = 0.673
	case 32:
		alpha = 0.697
	case 64:
		alpha = 0.709
	default:
		alpha = 0.7213 / (1 + 1.079/m)
	}
	var sum float64
	for i := range h.registers {
		sum += math.Pow(2.0, -float64(h.registers[i]))
	}
	// Estimativa
	E := alpha * m * m / sum

	var V float64
	for i := range h.registers {
		if h.registers[i] == 0 {
			V++
		}
	}
	if V > 0 {
		E_small := m * math.Log(m/V)
		if E <= 5.0*m {
			return E_small
		}
	}
	if E > (1.0/30.0)*math.Exp2(32) {
		return -math.Exp2(32) * math.Log(1-E/math.Exp2(32))
	}
	return E
}
