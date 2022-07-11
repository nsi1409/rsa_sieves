package main

import (
	"fmt"
	"math/big"
	"sort"
)

func main() {
	//test := *big.Int[8]{15, 7, 12, 0, 77, 8, 8522, 3}
	a, _ := new(big.Int).SetString("777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777", 10)
	fmt.Println("set:", a)

	//slice := make([]*big.Int, 0)
	//slice[0] := 15
	test := []*big.Int{big.NewInt(15), big.NewInt(7), big.NewInt(12), big.NewInt(0), big.NewInt(77), big.NewInt(8), big.NewInt(8522), a, big.NewInt(3)}

	fmt.Println("test array: ", test)
	fmt.Println("test[2]: ", test[2].Cmp(test[3]))

	sort.Slice(test, func(i, j int) bool {
    return (test[i].Cmp(test[j])) == -1
	})
	fmt.Println("sorted: ", test)

}

