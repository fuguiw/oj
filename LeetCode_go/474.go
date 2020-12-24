package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func count(str string) (c0 int, c1 int) {
	c0, c1 = 0, 0
	for i := range str {
		if str[i] == '0' {
			c0++
		} else {
			c1++
		}
	}
	return
}

func findMaxForm(strs []string, m int, n int) int {
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}

	for _, str := range strs {
		c0, c1 := count(str)
		for i := m; i >= c0; i-- {
			for j := n; j >= c1; j-- {
				dp[i][j] = max(dp[i][j], dp[i-c0][j-c1]+1)
			}
		}
	}

	return dp[m][n]
}
