package main

import (
	"sort"
)

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func find(n int, d *[]int) int {
	if (*d)[n] != 0 {
		return (*d)[n]
	}

	if n == 1 {
		return 0
	}

	if n%2 == 1 {
		(*d)[n] = find(3*n+1, d) + 1
	} else {
		(*d)[n] = find(n/2, d) + 1
	}

	return (*d)[n]
}

func getKth(lo int, hi int, k int) int {
	d := make([]int, 1000001)

	arr := make([][]int, hi-lo+1)
	for i := 0; i <= hi-lo; i++ {
		arr[i] = []int{lo + i, find(lo+i, &d)}
	}
	sort.Slice(arr, func(x, y int) bool {
		if arr[x][1] == arr[y][1] {
			return arr[x][0] < arr[y][0]
		}
		return arr[x][1] < arr[y][1]
	})

	return arr[k-1][0]
}
