package main

import "fmt"

func addToArrayForm(A []int, K int) []int {
	var k []int
	for K > 0 {
		k = append([]int{K % 10}, k...)
		K /= 10
	}
	fmt.Println(k)

	var ans []int
	i, j, p := len(A)-1, len(k)-1, 0
	for ; i >= 0 || j >= 0; i, j = i-1, j-1 {
		w := p
		if i >= 0 {
			w += A[i]
		}
		if j >= 0 {
			w += k[j]
		}
		ans = append([]int{w % 10}, ans...)
		p = w / 10
	}
	if p > 0 {
		ans = append([]int{1}, ans...)
	}

	return ans
}
