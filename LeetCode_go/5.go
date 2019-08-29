package main

func longestPalindrome(s string) string {
	dp := make([][]bool, len(s))
	for i := 0; i < len(s); i++ {
		dp[i] = make([]bool, len(s))
	}

	var result string
	for i := len(s) - 1; i >= 0; i-- {
		dp[i][i] = true
		if len(result) == 0 {
			result = s[i : i+1]
		}
		for j := i + 1; j < len(s); j++ {
			if s[i] == s[j] {
				dp[i][j] = true
			}
			if j > i+2 {
				dp[i][j] = dp[i][j] && dp[i+1][j-1]
			}

			if dp[i][j] && j-i+1 > len(result) {
				result = s[i : j+1]
			}
		}
	}

	return result
}
