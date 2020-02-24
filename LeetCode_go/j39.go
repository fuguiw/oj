package main

func majorityElement(nums []int) int {
	num, c := nums[0], 1
	for i := 1; i < len(nums); i++ {
		if nums[i] == num {
			c++
			continue
		}
		c--
		if c == 0 {
			num, c = nums[i], 1
		}
	}
	return num
}
