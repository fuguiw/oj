package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func stoneGame(piles []int) bool {
	n := len(piles)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, n)
	}

	for i := n - 1; i >= 0; i-- {
		dp[i][i] = piles[i]
		for j := i + 1; j < n; j++ {
			dp[i][j] = max(piles[i]-dp[i+1][j], piles[j]-dp[i][j-1])
		}
	}

	return dp[0][n-1] > 0
}
