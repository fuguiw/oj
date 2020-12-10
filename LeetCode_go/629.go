package main

const mod int = 1e9 + 7

func kInversePairs(n int, k int) int {
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, k+1)
	}

	for i := 1; i <= n; i++ {
		dp[i][0] = 1
		for j := 1; j <= k && j <= i*(i-1)/2; j++ {
			val := dp[i-1][j] + mod
			if j >= i {
				val -= dp[i-1][j-i]
			}
			val %= mod
			dp[i][j] = (dp[i][j-1] + val) % mod
		}
	}

	return dp[n][k]
}
