package main

import (
	"sort"
)

func canReorderDoubled(A []int) bool {
	sort.Slice(A, func(i, j int) bool {
		if A[i] < 0 && A[j] < 0 {
			return A[i] < A[j]
		} else {
			return A[i] > A[j]
		}
	})

	m := make(map[int]int)
	cnt := 0
	for _, num := range A {
		if m[num*2] > 0 {
			m[num*2]--
			cnt += 2
		} else {
			m[num]++
		}
	}

	return cnt == len(A)
}
