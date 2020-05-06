package main

import (
	"fmt"
	"math"
)

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func mincostTickets(days []int, costs []int) int {
	n := len(days)
	if n == 0 {
		return 0
	}

	dp := make([][]int, len(days))
	for i := range days {
		dp[i] = make([]int, 4)
	}

	dp[0][0] = costs[0]
	dp[0][1] = costs[1]
	dp[0][2] = costs[2]
	dp[0][3] = math.MaxInt32
	for i := 1; i < n; i++ {
		dp[i][0] = math.MaxInt32
		dp[i][1] = math.MaxInt32
		dp[i][2] = math.MaxInt32
		dp[i][3] = math.MaxInt32
		for j := 0; j < 4; j++ {
			dp[i][0] = min(dp[i][0], dp[i-1][j]+costs[0])
			dp[i][1] = min(dp[i][1], dp[i-1][j]+costs[1])
			dp[i][2] = min(dp[i][2], dp[i-1][j]+costs[2])
		}
		for j := i - 1; j >= 0; j-- {
			if days[i]-days[j] < 7 {
				dp[i][3] = min(dp[i][3], dp[j][1])
			} else if days[i]-days[j] < 30 {
				dp[i][3] = min(dp[i][3], dp[j][2])
			} else {
				break
			}
		}
		fmt.Println(dp[i][0], dp[i][1], dp[i][2], dp[i][3])
	}

	ans := math.MaxInt32
	for i := 0; i < 4; i++ {
		ans = min(ans, dp[n-1][i])
	}
	return ans
}
