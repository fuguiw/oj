package main

import "container/list"

func nextGreaterElements(nums []int) []int {
	result := make([]int, len(nums))
	st := list.New()

	for k := 0; k < 2; k++ {
		for i := len(nums) - 1; i >= 0; i-- {
			if result[i] == 0 {
				result[i] = -1
			}
			for st.Len() != 0 {
				top := st.Back()
				if top.Value.(int) > nums[i] {
					result[i] = top.Value.(int)
					break
				}
				st.Remove(top)
			}

			st.PushBack(nums[i])
		}
	}

	return result
}
