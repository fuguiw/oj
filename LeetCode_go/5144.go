package main

import "fmt"

func matrixBlockSum(mat [][]int, K int) [][]int {
	if mat == nil {
		return nil
	}

	ans := make([][]int, len(mat))
	rs := make([][]int, len(mat))
	for i := 0; i < len(mat); i++ {
		ans[i] = make([]int, len(mat[i]))
		rs[i] = make([]int, len(mat[i]))
	}

	for i := 0; i < len(mat); i++ {
		for j := 0; j < len(mat[i]); j++ {
			rs[i][j] = mat[i][j]
			if j > 0 {
				rs[i][j] += rs[i][j-1]
			}
		}
	}

	for i := 0; i < len(mat); i++ {
		for j := 0; j < len(mat[i]); j++ {
			rb := i - K
			if rb < 0 {
				rb = 0
			}
			re := i + K
			if re >= len(mat) {
				re = len(mat) - 1
			}

			cb := j - K
			if cb < 0 {
				cb = 0
			}
			ce := j + K
			if ce >= len(mat[i]) {
				ce = len(mat[i]) - 1
			}

			for k := rb; k <= re; k++ {
				ans[i][j] += rs[k][ce] - rs[k][cb] + mat[k][cb]
			}
		}
	}

	return ans
}
