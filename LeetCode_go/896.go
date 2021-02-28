package main

import "sort"

func isMonotonic(A []int) (ans bool) {
	return sort.IsSorted(sort.IntSlice(A)) || sort.IsSorted(sort.Reverse(sort.IntSlice(A)))
}
