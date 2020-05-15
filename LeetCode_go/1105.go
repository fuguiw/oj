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

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func minHeightShelves(books [][]int, shelf_width int) int {
	n := len(books)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}

	ans := math.MaxInt32
	for i := 1; i <= n; i++ {
		for j := i; j >= 0; j-- {
			if j == 0 {
				dp[i][j] = math.MaxInt32
				continue
			}
			w, h := 0, 0
			dp[i][j] = math.MaxInt32
			for k := i; k >= j; k-- {
				w += books[k-1][0]
				h = max(h, books[k-1][1])
				if w > shelf_width {
					break
				}

				dp[i][j] = min(dp[i][j], dp[k-1][j-1]+h)
				if i == n {
					ans = min(ans, dp[i][j])
					fmt.Println(w, i, j, dp[i][j])
				}
			}
		}
	}
	return ans
}
