package main

const mod int = 1e9 + 7

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func profitableSchemes(n int, minProfit int, group []int, profit []int) int {
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, minProfit+1)
		dp[i][0] = 1
	}

	for i, g := range group {
		p := profit[i]
		for j := n; j >= g; j-- {
			for k := minProfit; k >= 0; k-- {
				dp[j][k] = (dp[j][k] + dp[j-g][max(0, k-p)]) % mod
			}
		}
	}

	return dp[n][minProfit]
}
