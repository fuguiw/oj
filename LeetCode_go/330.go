package main

func minPatches(nums []int, n int) int {
	ans := 0
	for i, x := 0, 1; x <= n; {
		if i < len(nums) && nums[i] <= x {
			x += nums[i]
			i++
		} else {
			x *= 2
			ans++
		}
	}

	return ans
}
