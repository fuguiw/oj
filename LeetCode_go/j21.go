package main

func exchange(nums []int) []int {
	for i, j := -1, 0; j < len(nums); j++ {
		if nums[j]%2 == 1 {
			i++
			nums[i], nums[j] = nums[j], nums[i]
		}
	}
	return nums
}
