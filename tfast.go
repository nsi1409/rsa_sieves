package main

import (
	"fmt"
	"math/big"
	//"sort"
)

type key_val struct {
	key *big.Int
	val *big.Int
}

func init_loop(n *big.Int) []key_val {
	arr := make([]key_val, 8000)
	cast_one, _ := new(big.Int).SetString("1", 10)
	run, _ := new(big.Int).SetString("0", 10)
	for i := 0; i < 8000; i++ {
		run.Add(run, cast_one)
		//arr[i] = key_val{key: run, val: run}
		arr = append(arr, key_val{key: run.value, val: run.value})
	}
	return arr
}

func main() {
	n, _ := new(big.Int).SetString("0", 10)
	run, _ := new(big.Int).SetString("0", 10)
	inc, _ := new(big.Int).SetString("-1", 10)
	fmt.Println("run: ", run, " inc: ", inc, "n: ", n)
	arr := init_loop(n)
	fmt.Println("init loop: ", arr, " ex[13]: ", arr[13].key, " ex[253]: ", arr[253].key)
}


