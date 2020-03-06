package main

import (
	"container/list"
)

func validateStackSequences(pushed []int, popped []int) bool {
	st := list.New()

	var i, j int
	for i, j = 0, 0; j < len(popped); {
		if st.Len() == 0 || popped[j] != st.Back().Value.(int) {
			if i == len(pushed) {
				break
			}
			st.PushBack(pushed[i])
			i++
		} else {
			st.Remove(st.Back())
			j++
		}
	}

	if i == len(pushed) && st.Len() == 0 {
		return true
	}

	return false
}
