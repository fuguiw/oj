package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func canJump(nums []int) bool {
	j := nums[0]
	for i := 0; i < len(nums) && i <= j; i++ {
		j = max(j, nums[i]+i)
	}

	return j >= len(nums)-1
}
