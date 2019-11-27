package main

import "fmt"

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maximalSquare(matrix [][]byte) int {
	if len(matrix) == 0 {
		return 0
	}
	left := make([][]int, len(matrix)+1)
	up := make([][]int, len(matrix)+1)
	d := make([][]int, len(matrix)+1)
	for i := 0; i < len(matrix)+1; i++ {
		left[i] = make([]int, len(matrix[0])+1)
		up[i] = make([]int, len(matrix[0])+1)
		d[i] = make([]int, len(matrix[0])+1)
	}

	ans := 0
	for i := 1; i < len(matrix)+1; i++ {
		for j := 1; j < len(matrix[0])+1; j++ {
			if matrix[i-1][j-1] == '1' {
				up[i][j] = up[i-1][j] + 1
				left[i][j] = left[i][j-1] + 1
				d[i][j] = min(d[i-1][j-1]+1, min(left[i][j], up[i][j]))
				ans = max(ans, d[i][j])
			}
		}
	}

	return ans * ans
}
