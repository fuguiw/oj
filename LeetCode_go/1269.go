package main

const mod int = 1e9 + 7

func numWays(steps int, arrLen int) int {
	dp := make([]int, arrLen+2)
	dp[1] = 1
	next := make([]int, arrLen+2)
	for i := 1; i <= steps; i++ {
		for j := 1; j <= arrLen; j++ {
			next[j] = (dp[j-1] + dp[j] + dp[j+1]) % mod
			if next[j] == 0 {
				break
			}
		}
		dp, next = next, dp
	}
	return dp[1]
}
