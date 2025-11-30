package main

import (
	"fmt"
	"log"

	"github.com/PedroBSantos/data-structs/hyperloglog/src/structure"
)

func main() {
	h, err := structure.NewHyperLogLog(16)
	if err != nil {
		log.Fatal(err.Error())
	}
	h.Add("Pedro")
	h.Add("Pedro")
	h.Add("Rafael")
	h.Add("Rafael")
	h.Add("Miguel")
	estimate := h.Estimate()
	fmt.Println("Elementos distintos:", estimate)
}
