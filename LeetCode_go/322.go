package main

import "math"

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func coinChange(coins []int, amount int) int {
	dp := make([]int, amount+1)

	for i := 1; i <= amount; i++ {
		tmp := math.MaxInt32
		for _, coin := range coins {
			if coin <= i {
				tmp = min(tmp, dp[i-coin]+1)
			}
		}
		dp[i] = tmp
	}

	if dp[amount] == math.MaxInt32 {
		return -1
	}
	return dp[amount]
}
