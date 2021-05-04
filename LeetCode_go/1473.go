package main

import "math"

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func minCost(houses []int, cost [][]int, m int, n int, target int) int {
	//dp[i][j][k]  = min(dp[i-1][j][k], dp[i-1][x][k-1]) + cost[i][j]

	dp := make([][][]int, m)
	for i := range dp {
		dp[i] = make([][]int, n)
		for j := range dp[i] {
			dp[i][j] = make([]int, m)
			for k := range dp[i][j] {
				dp[i][j][k] = -1
			}
		}
	}

	find := func(i, j, k int) {
		if i == 0 {
			if houses[i] == 0 {
				dp[i][j][k] = cost[i][j]
			} else if houses[i]-1 == j {
				dp[i][j][k] = 0
			}
			return
		}

		c := math.MaxInt32
		for x := 0; x < n; x++ {
			if x == j && dp[i-1][x][k] != -1 {
				c = min(c, dp[i-1][x][k])
			}
			if x != j && k > 0 && dp[i-1][x][k-1] != -1 {
				c = min(c, dp[i-1][x][k-1])
			}
		}
		if c != math.MaxInt32 {
			dp[i][j][k] = c
		}
		if houses[i] == 0 && dp[i][j][k] != -1 {
			dp[i][j][k] += cost[i][j]
		}
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if houses[i] != 0 && houses[i]-1 != j {
				continue
			}
			for k := 0; k <= i; k++ {
				find(i, j, k)
			}
		}
	}
	ans := -1
	for i := 0; i < n; i++ {
		if dp[m-1][i][target-1] != -1 {
			if ans == -1 {
				ans = dp[m-1][i][target-1]
			} else {
				ans = min(ans, dp[m-1][i][target-1])
			}
		}
	}
	return ans
}
