package main

import "sort"

func kthLargestValue(matrix [][]int, k int) int {
	n, m := len(matrix), len(matrix[0])
	xs := make([][]int, n)
	for i := range xs {
		xs[i] = make([]int, m)
	}
	for i := range xs {
		for j := range xs[i] {
			xs[i][j] = matrix[i][j]
			if i != 0 {
				xs[i][j] ^= xs[i-1][j]
			}
		}
	}
	arr := make([]int, n*m)
	idx := 0
	for i := range matrix {
		x := 0
		for j := range matrix[i] {
			x ^= xs[i][j]
			arr[idx] = x
			idx++
		}
	}
	sort.Ints(arr)
	return arr[n*m-k]
}
