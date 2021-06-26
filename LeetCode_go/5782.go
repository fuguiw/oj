package main

func max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

func maxAlternatingSum(nums []int) int64 {
	n := len(nums)
	dp := make([][]int64, n+1)
	dp[0] = make([]int64, 2)
	for i := 1; i <= n; i++ {
		dp[i] = make([]int64, 2)
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]+int64(nums[i-1]))
		dp[i][1] = max(dp[i-1][1], dp[i-1][0]-int64(nums[i-1]))
	}

	return max(dp[n][0], dp[n][1])
}
