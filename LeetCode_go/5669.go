package main

func canChoose(groups [][]int, nums []int) bool {
	idx := 0
	for _, group := range groups {
		find := false
		for idx < len(nums)-len(group) {
			i := 0
			for ; i < len(group); i++ {
				if group[i] != nums[idx+i] {
					idx++
					break
				}
			}
			if i == len(group) {
				find = true
				idx += len(group)
				break
			}
		}
		if !find {
			return false
		}
	}

	return true
}
