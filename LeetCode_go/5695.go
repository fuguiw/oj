package main

import "math/bits"

func gcd(x, y int) int {
	if y == 0 {
		return x
	}
	return gcd(y, x%y)
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxScore(nums []int) int {
	n := len(nums)
	dp := make([]int, 1<<n)
	g := make([][]int, n)
	for i := range g {
		g[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			g[i][j] = gcd(nums[i], nums[j])
		}
	}

	for state := 0; state < 1<<n; state++ {
		count := bits.OnesCount(uint(state))
		if count&1 != 0 {
			continue
		}
		now := count/2 + 1
		for i := 0; i < n; i++ {
			for j := i + 1; j < n; j++ {
				if state&(1<<i) != 0 || state&(1<<j) != 0 {
					continue
				}
				next := state | 1<<i | 1<<j
				dp[next] = max(dp[next], dp[state]+now*g[i][j])
			}
		}
	}
	return dp[len(dp)-1]
}
