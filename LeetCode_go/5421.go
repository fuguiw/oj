package main

import (
	"fmt"
	"math"
	"sort"
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func minDistance(houses []int, k int) int {
	n := len(houses)
	sort.Ints(houses)
	fmt.Println(houses)
	dis := make([][]int, n+2)
	for i := range dis {
		dis[i] = make([]int, n+2)
	}
	for i := 1; i <= n; i++ {
		for j := i; j <= n; j++ {
			mid := (j + i) / 2
			p := houses[mid-1]
			for t := i; t <= j; t++ {
				dis[i][j] += abs(houses[t-1] - p)
			}
		}
	}

	dp := make([][]int, n+2)
	for i := range dp {
		dp[i] = make([]int, n+2)
		for j := range dp[i] {
			dp[i][j] = math.MaxInt32
		}
	}
	dp[0][0] = 0
	for i := 1; i <= n; i++ {
		for t := 1; t <= i && t <= k; t++ {
			for j := i - 1; j >= 0; j-- {
				dp[i][t] = min(dp[i][t], dp[j][t-1]+dis[j+1][i])
			}
		}
	}
	fmt.Println(dp)
	return dp[n][k]
}
