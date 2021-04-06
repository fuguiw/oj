package main

func removeDuplicates(nums []int) int {
	l := 1
	cnt := 1
	for i := 1; i < len(nums); i++ {
		if nums[i] != nums[i-1] {
			nums[l] = nums[i]
			l++
			cnt = 1
		} else {
			cnt++
			if cnt <= 2 {
				nums[l] = nums[i]
				l++
			}
		}
	}
	return l
}
