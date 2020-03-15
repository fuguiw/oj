package main

import "container/list"

func maxSlidingWindow(nums []int, k int) []int {
	m := list.New()
	var ans []int

	for i, num := range nums {
		for m.Len() != 0 {
			if m.Back().Value.(int) >= num {
				break
			}
			m.Remove(m.Back())
		}
		m.PushBack(nums[i])
		if i >= k-1 {
			if i >= k && nums[i-k] == m.Front().Value.(int) {
				m.Remove(m.Front())
			}
			ans = append(ans, m.Front().Value.(int))
		}
	}

	return ans
}
