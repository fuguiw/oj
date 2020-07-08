package main

import (
	"math"
)

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func splitArray(nums []int, m int) int {
	n := len(nums)
	dp := make([][]int, n+1)
	sum := make([]int, n+1)
	for i := range dp {
		dp[i] = make([]int, m+1)
	}

	for i := 1; i <= n; i++ {
		sum[i] = sum[i-1] + nums[i-1]
	}

	for i := 1; i <= n; i++ {
		dp[i][0] = math.MaxInt32
		for j := 1; j <= min(i, m); j++ {
			dp[i][j] = math.MaxInt32
			for k := j - 1; k < i; k++ {
				dp[i][j] = min(dp[i][j], max(dp[k][j-1], sum[i]-sum[k]))
			}
		}
	}

	return dp[n][m]
}
