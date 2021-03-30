package main

import "sort"

func searchMatrix(matrix [][]int, target int) bool {
	m, n := len(matrix), len(matrix[0])
	row := sort.Search(m, func(i int) bool {
		return matrix[i][0] > target
	}) - 1
	if row < 0 {
		return false
	}

	col := sort.SearchInts(matrix[row], target)
	if col < n && matrix[row][col] == target {
		return true
	}
	return false
}
