package main

import (
	"math"
	"sort"
)

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func min(x, y int64) int64 {
	if x < y {
		return x
	}
	return y
}

func smallestDifference(a []int, b []int) int {
	sort.Ints(a)
	sort.Ints(b)

	var ans int64 = math.MaxInt32
	for i, j := 0, 0; i < len(a) && j < len(b); {
		x, y := int64(a[i]), int64(b[j])
		ans = min(ans, abs(x-y))
		if x < y {
			i++
		} else {
			j++
		}
	}
	return int(ans)
}
