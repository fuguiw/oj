package main

import "sort"

func searchMatrix(matrix [][]int, target int) bool {
	m, n := len(matrix), len(matrix[0])
	for i, j := 0, n-1; i >= 0 && i < m && j >= 0 && j < n; {
		if matrix[i][j] == target {
			return true
		}
		if matrix[i][j] > target {
			j--
		} else {
			i++
		}
	}

	return false
}
