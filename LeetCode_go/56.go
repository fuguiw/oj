package main

import "sort"

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func merge(intervals [][]int) [][]int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	var ans [][]int
	if len(intervals) == 0 {
		return ans
	}

	begin, end := intervals[0][0], intervals[0][1]
	for i := range intervals {
		tb, te := intervals[i][0], intervals[i][1]
		if tb <= end {
			begin = min(begin, tb)
			end = max(end, te)
		} else {
			ans = append(ans, []int{begin, end})
			begin, end = tb, te
		}
	}
	ans = append(ans, []int{begin, end})

	return ans
}
