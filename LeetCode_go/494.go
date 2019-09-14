package main

func find(nums []int, s, sum, index int, result *int) {
	if index == len(nums) {
		if s == sum {
			*result++
		}
		return
	}

	find(nums, s, sum+nums[index], index+1, result)
	find(nums, s, sum-nums[index], index+1, result)
}

func findTargetSumWays(nums []int, S int) int {
	result := 0
	find(nums, S, 0, 0, &result)
	return result
}
