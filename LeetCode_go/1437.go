package main

func kLengthApart(nums []int, k int) bool {
	idx := -1
	for i := range nums {
		if nums[i] == 1 {
			if idx != -1 && i-idx-1 < k {
				return false
			}
			idx = i
		}
	}
	return true
}
