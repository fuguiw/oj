package main

import (
	"container/list"
)

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func shortestSubarray(A []int, K int) int {
	n := len(A)
	p := make([]int, n+1)
	for i := 0; i < n; i++ {
		p[i+1] = p[i] + A[i]
	}

	result := n + 1
	l := list.New()
	for i := 0; i < n+1; i++ {
		for l.Len() != 0 && p[i] <= p[l.Back().Value.(int)] {
			l.Remove(l.Back())
		}
		for l.Len() != 0 && p[i] >= p[l.Front().Value.(int)]+K {
			result = min(result, i-l.Front().Value.(int))
			l.Remove(l.Front())
		}
		l.PushBack(i)
	}

	if result == n+1 {
		result = -1
	}
	return result
}
