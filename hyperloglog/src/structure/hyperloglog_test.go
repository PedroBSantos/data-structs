package structure_test

import (
	"math"
	"testing"

	"github.com/PedroBSantos/data-structs/hyperloglog/src/structure"
	"github.com/stretchr/testify/require"
)

func TestNewHyperLogLog(t *testing.T) {
	hashPrefixLengthOnBits := uint(8)
	hyperLogLog, _ := structure.NewHyperLogLog(hashPrefixLengthOnBits)
	require.NotNil(t, hyperLogLog)
	expectedRegistersCount := int(math.Pow(2, float64(hashPrefixLengthOnBits)))
	require.Equal(t, expectedRegistersCount, hyperLogLog.Registers())
}

func TestGenerateHash(t *testing.T) {
	hashPrefixLengthOnBits := uint(8)
	hyperLogLog, _ := structure.NewHyperLogLog(hashPrefixLengthOnBits)
	inputStr := "test-generate-hash"
	hash, err := hyperLogLog.GenerateHash(inputStr)
	require.Nil(t, err)
	require.NotNil(t, hash)
	expectedHashBytesCount := 16
	require.Equal(t, expectedHashBytesCount, len(hash))
}

func TestExtractFirstPBits_PEquals8(t *testing.T) {
	hashPrefixLengthOnBits := uint(8)
	hyperLogLog, _ := structure.NewHyperLogLog(hashPrefixLengthOnBits)
	inputStr := "Hello, world"
	hash, err := hyperLogLog.GenerateHash(inputStr)
	require.Nil(t, err)
	firstBits, restOfHash, _ := hyperLogLog.ExtractFirstPBits(hash)
	EXPECTED_FIRST_BITS := uint64(188)
	expectedHashBytesCount := 15
	require.Equal(t, EXPECTED_FIRST_BITS, firstBits)
	require.Equal(t, expectedHashBytesCount, len(restOfHash))
}

func TestExtractFirstPBits_P8Multiple(t *testing.T) {
	hashPrefixLengthOnBits := uint(16)
	hyperLogLog, _ := structure.NewHyperLogLog(hashPrefixLengthOnBits)
	inputStr := "Hello, world"
	hash, err := hyperLogLog.GenerateHash(inputStr)
	require.Nil(t, err)
	firstBits, restOfHash, _ := hyperLogLog.ExtractFirstPBits(hash)
	EXPECTED_FIRST_BITS := uint64(48238)
	expectedHashBytesCount := 14
	require.Equal(t, EXPECTED_FIRST_BITS, firstBits)
	require.Equal(t, expectedHashBytesCount, len(restOfHash))
}

func TestExtractFirstPBits_PLessThan8(t *testing.T) {
	hashPrefixLengthOnBits := uint(5)
	hyperLogLog, _ := structure.NewHyperLogLog(hashPrefixLengthOnBits)
	inputStr := "Hello, world"
	hash, err := hyperLogLog.GenerateHash(inputStr)
	require.Nil(t, err)
	firstBits, restOfHash, _ := hyperLogLog.ExtractFirstPBits(hash)
	EXPECTED_FIRST_BITS := uint64(23)
	expectedHashBytesCount := 16
	require.Equal(t, EXPECTED_FIRST_BITS, firstBits)
	require.Equal(t, expectedHashBytesCount, len(restOfHash))
}

func TestExtractFirstPBits_PGreaterThan8(t *testing.T) {
	hashPrefixLengthOnBits := uint(10)
	hyperLogLog, _ := structure.NewHyperLogLog(hashPrefixLengthOnBits)
	inputStr := "Hello, world"
	hash, err := hyperLogLog.GenerateHash(inputStr)
	require.Nil(t, err)
	firstBits, restOfHash, _ := hyperLogLog.ExtractFirstPBits(hash)
	EXPECTED_FIRST_BITS := uint64(753)
	expectedHashBytesCount := 16
	require.Equal(t, EXPECTED_FIRST_BITS, firstBits)
	require.Equal(t, expectedHashBytesCount, len(restOfHash))
}
