package main

func findTargetSumWays(nums []int, target int) int {
	ans := 0
	var find func(int, int)
	find = func(idx, sum int) {
		if idx == len(nums) {
			if sum == target {
				ans++
			}
			return
		}
		find(idx+1, sum+nums[idx])
		find(idx+1, sum-nums[idx])
	}
	find(0, 0)

	return ans
}
