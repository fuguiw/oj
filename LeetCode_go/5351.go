package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxSizeSlices(slices []int) int {
	n := len(slices)
	picks := n / 3
	dp := make([][][]int, n)
	for i := range dp {
		dp[i] = make([][]int, picks+1)
		for j := range dp[i] {
			dp[i][j] = make([]int, 2)
		}
	}

	ans := 0

	dp[0][1][1] = slices[0]
	for i := 1; i < n; i++ {
		if i == n-1 {
			continue
		}
		for j := 1; j <= picks; j++ {
			if i == 1 {
				dp[i][j][0] = dp[i-1][j][1]
				continue
			}
			dp[i][j][1] = dp[i-1][j-1][0] + slices[i]
			dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1])
		}
		ans = max(ans, max(dp[i][picks][1], dp[i][picks][0]))
	}

	dp[0][1][1] = 0
	for i := 1; i < n; i++ {
		for j := 1; j <= picks; j++ {
			dp[i][j][1] = dp[i-1][j-1][0] + slices[i]
			dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1])
		}
		ans = max(ans, max(dp[i][picks][1], dp[i][picks][0]))
	}

	return ans
}
