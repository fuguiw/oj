package main

import (
	"math"
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func numsSameConsecDiff(N int, K int) []int {
	dp := make([][][]int, 10)
	for i := range dp {
		dp[i] = make([][]int, 10)
		if i > 0 {
			dp[1][i] = []int{i}
		}
	}
	dp[1][0] = []int{0}

	for i := 2; i <= N; i++ {
		for j := 0; j <= 9; j++ {
			n := int(math.Pow10(i-1)) * j
			for k := 0; k <= 9; k++ {
				if abs(j-k) == K {
					for _, num := range dp[i-1][k] {
						//fmt.Println(i, k, num)
						dp[i][j] = append(dp[i][j], n+num)
					}
				}
			}
		}
	}

	var ans []int
	for i := 0; i <= 9; i++ {
		if N != 1 && i == 0 {
			continue
		}
		ans = append(ans, dp[N][i]...)
	}
	return ans
}
