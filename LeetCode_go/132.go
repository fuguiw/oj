package main

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func minCut(s string) int {
	n := len(s)
	isp := make([][]int, n)
	for i := range isp {
		isp[i] = make([]int, n)
	}

	find := func(left, right int) {
		for left >= 0 && right < n && s[left] == s[right] {
			isp[left][right] = 1
			left--
			right++
		}
	}
	for i := range s {
		find(i, i)
		find(i, i+1)
	}

	dp := make([]int, n+1)
	for i := range dp {
		dp[i] = i
	}
	for j := range s {
		for i := 0; i <= j; i++ {
			if isp[i][j] == 1 {
				dp[j+1] = min(dp[j+1], dp[i]+1)
			}
		}
	}
	return dp[n] - 1
}
