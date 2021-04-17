package main

func minOperations(nums []int) int {
	ans := 0
	for i := range nums {
		if i == 0 || nums[i] > nums[i-1] {
			continue
		}
		ans += nums[i-1] - nums[i] + 1
		nums[i] = nums[i-1] + 1
	}
	return ans
}
