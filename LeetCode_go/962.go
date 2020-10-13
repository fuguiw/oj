package main

import "container/list"

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxWidthRamp(A []int) int {
	st := list.New()
	for i := range A {
		for st.Len() == 0 || A[st.Back().Value.(int)] > A[i] {
			st.PushBack(i)
		}
	}

	ans := 0
	for i := len(A) - 1; i > ans; i-- {
		for st.Len() > 0 && A[st.Back().Value.(int)] <= A[i] {
			ans = max(ans, i-st.Back().Value.(int))
			st.Remove(st.Back())
		}
	}

	return ans
}
