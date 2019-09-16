package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxCoins(nums []int) int {
	nums = append([]int{1}, append(nums, 1)...)
	n := len(nums)

	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)
	}

	for len := 2; len < n; len++ {
		for i := 0; i < n-len; i++ {
			j := i + len
			for k := i + 1; k < j; k++ {
				dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j])
			}
		}
	}

	return dp[0][n-1]
}
