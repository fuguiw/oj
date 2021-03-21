package main

import "math"

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
	n := len(jobs)
	tot := make([]int, 1<<n)
	for i := 1; i < 1<<n; i++ {
		for j := 0; j < n; j++ {
			if i&(1<<j) == 0 {
				continue
			}
			left := i - (1 << j)
			tot[i] = tot[left] + jobs[j]
			break
		}
	}

	dp := make([][]int, k)
	for i := range dp {
		dp[i] = make([]int, 1<<n)
	}
	for i := range dp[0] {
		dp[0][i] = tot[i]
	}

	for j := 1; j < k; j++ {
		for i := 0; i < 1<<n; i++ {
			minv := math.MaxInt32
			for s := i; s != 0; s = (s - 1) & i {
				left := i - s
				val := max(dp[j-1][left], tot[s])
				minv = min(minv, val)
			}
			dp[j][i] = minv
		}
	}
	return dp[k-1][(1<<n)-1]
}
