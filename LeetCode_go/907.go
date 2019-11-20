package main

import (
	"container/list"
)

func sumSubarrayMins(A []int) int {
	stack := list.New()
	left := make([]int, len(A))
	for i := 0; i < len(A); i++ {
		for stack.Len() != 0 && A[stack.Back().Value.(int)] >= A[i] {
			stack.Remove(stack.Back())
		}
		if stack.Len() == 0 {
			left[i] = -1
		} else {
			left[i] = stack.Back().Value.(int)
		}
		stack.PushBack(i)
	}

	stack = list.New()
	right := make([]int, len(A))
	for i := len(A) - 1; i >= 0; i-- {
		for stack.Len() != 0 && A[stack.Back().Value.(int)] > A[i] {
			stack.Remove(stack.Back())
		}
		if stack.Len() == 0 {
			right[i] = len(A)
		} else {
			right[i] = stack.Back().Value.(int)
		}
		stack.PushBack(i)
	}

	ans := 0
	for i := range A {
		ans = (ans + (i-left[i])*(right[i]-i)*A[i]) % 1000000007
	}
	return ans
}
