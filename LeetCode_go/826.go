package main

import (
	"sort"
)

func maxProfitAssignment(difficulty []int, profit []int, worker []int) int {
	var d [][]int
	for i := 0; i < len(difficulty); i++ {
		d = append(d, []int{difficulty[i], profit[i]})
	}

	sort.Slice(d, func(i, j int) bool {
		return d[i][0] < d[j][0]
	})

	for i := 1; i < len(difficulty); i++ {
		if d[i][1] < d[i-1][1] {
			d[i][1] = d[i-1][1]
		}
	}

	sort.Slice(worker, func(i, j int) bool {
		return worker[i] < worker[j]
	})

	idx := len(difficulty) - 1
	ans := 0
	for i := len(worker) - 1; i >= 0; i-- {
		for idx > 0 && d[idx][0] > worker[i] {
			idx--
		}
		if d[idx][0] <= worker[i] {
			ans += d[idx][1]
		}
	}

	return ans
}
