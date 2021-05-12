package main

func xorQueries(arr []int, queries [][]int) []int {
	n := len(arr)
	xor1 := make([]int, n+1)
	xor2 := make([]int, n+1)
	tot := 0
	for i := range arr {
		xor1[i+1] = xor1[i] ^ arr[i]
		tot ^= arr[i]
	}
	for i := n - 1; i >= 0; i-- {
		xor2[i] = xor2[i+1] ^ arr[i]
	}

	ans := make([]int, len(queries))
	for i, query := range queries {
		ans[i] = tot ^ xor1[query[0]] ^ xor2[query[1]+1]
	}

	return ans
}
