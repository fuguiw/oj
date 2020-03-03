package main

import (
	"strings"
)

func wordBreak(s string, wordDict []string) bool {
	dp := make([][]int, len(s))
	for i := 0; i < len(s); i++ {
		dp[i] = make([]int, len(s))
	}

	for _, word := range wordDict {
		i := 0
		for i != -1 {
			j := strings.Index(s[i:], word)
			if j == -1 {
				break
			}
			i += j
			dp[i][i+len(word)-1] = 1
			i++
		}
	}

	for i := 0; i < len(s)-1; i++ {
		for j := i + 1; j < len(s); j++ {
			if dp[0][i] == 1 && dp[i+1][j] == 1 {
				dp[0][j] = 1
			}
		}
	}

	return dp[0][len(s)-1] == 1
}
