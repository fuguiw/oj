package main

func combinationSum4(nums []int, target int) int {
	dp := make([]int, target+1)
	dp[0] = 1
	for i := 1; i <= target; i++ {
		for _, num := range nums {
			if num > i {
				continue
			}
			dp[i] += dp[i-num]
		}
	}
	return dp[target]
}
