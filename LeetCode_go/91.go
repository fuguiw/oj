package main

func numDecodings(s string) int {
	n := len(s)
	dp := make([]int, n+1)
	dp[0] = 1

	for i := 0; i < n; i++ {
		c := int(s[i] - '0')
		if c > 0 {
			dp[i+1] += dp[i]
		}
		if i > 0 {
			num := int(s[i-1]-'0')*10 + c
			if num >= 10 && num <= 26 {
				dp[i+1] += dp[i-1]
			}
		}
	}

	return dp[n]
}
