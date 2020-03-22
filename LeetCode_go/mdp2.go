package main

import "math"

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func minPathSum(grid [][]int) int {
	if len(grid) == 0 {
		return 0
	}
	n, m := len(grid), len(grid[0])
	dp := make([][]int, n)

	for i := range grid {
		dp[i] = make([]int, m)
		for j := range grid[i] {
			dp[i][j] = grid[i][j]
			tmp := math.MaxInt32
			if i > 0 {
				tmp = min(tmp, dp[i-1][j])
			}
			if j > 0 {
				tmp = min(tmp, dp[i][j-1])
			}
			if tmp != math.MaxInt32 {
				dp[i][j] += tmp
			}
		}
	}
	return dp[n-1][m-1]
}
