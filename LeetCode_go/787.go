package main

import "fmt"

func findCheapestPrice(n int, flights [][]int, src int, dst int, K int) int {
	dp := make([][][]int, n)
	for i := range dp {
		dp[i] = make([][]int, n)
		for j := range dp[i] {
			dp[i][j] = make([]int, n)
		}
	}

	for _, flight := range flights {
		dp[flight[0]][flight[1]][0] = flight[2]
	}

	for k := 1; k <= K; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				dp[i][j][k] = dp[i][j][k-1]
				for m := 0; m < n; m++ {
					if dp[i][m][k-1] != 0 && dp[m][j][0] != 0 {
						if dp[i][j][k] == 0 || dp[i][j][k] > dp[i][m][k-1]+dp[m][j][0] {
							dp[i][j][k] = dp[i][m][k-1] + dp[m][j][0]
						}
					}
				}
			}
		}
	}
	fmt.Println(dp)

	if dp[src][dst][K] == 0 {
		return -1
	}
	return dp[src][dst][K]
}
