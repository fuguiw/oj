package main

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func jump(nums []int) int {
	dp := make([]int, len(nums))

	for i := 0; i < len(nums); i++ {
		for j := 1; j <= nums[i] && i+j < len(nums); j++ {
			if dp[i+j] == 0 {
				dp[i+j] = dp[i] + 1
			} else {
				dp[i+j] = min(dp[i+j], dp[i]+1)
			}
		}
	}

	return dp[len(nums)-1]
}
