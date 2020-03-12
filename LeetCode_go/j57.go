package main

func twoSum(nums []int, target int) []int {
	i, j := 0, len(nums)-1
	for i < j {
		if nums[i]+nums[j] > target {
			j--
		} else if nums[i]+nums[j] < target {
			i++
		} else {
			return []int{nums[i], nums[j]}
		}
	}
	return []int{}
}
