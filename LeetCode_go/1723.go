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
	return x + y - max(x, y)
}

func minimumTimeRequired(jobs []int, k int) int {
	// dp[i][j] = min(dp[i][j] + max(dp[i-1][k], tot[left])

	n := len(jobs)
	tot := make([]int, 1<<n)
	for i := 0; i < 1<<n; i++ {
		for j := 0; j < n; j++ {
			if i&(1<<j) == 0 {
				continue
			}
			left := i - (1 << j)
			tot[i] = tot[left] + jobs[j]
		}
	}

	dp := make([][]int, k)
	for i := range dp {
		dp[i] = make([]int, 1<<n)
	}

	for i := 0; i < k; i++ {
		for j := range dp[i] {
			if i == 0 {
				dp[i][j] = tot[j]
				continue
			}
			minv := math.MaxInt32
			for s := j; s != 0; s = (s - 1) & j {
				left := j - s
				val := max(dp[i-1][s], tot[left])
				minv = min(minv, val)
			}
			dp[i][j] = minv
		}
	}
	return dp[k-1][1<<n-1]
}
