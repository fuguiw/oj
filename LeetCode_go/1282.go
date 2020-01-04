package main

import "sort"

func groupThePeople(groupSizes []int) [][]int {
	var group [][]int
	for i, s := range groupSizes {
		group = append(group, []int{i, s})
	}

	sort.Slice(group, func(i, j int) bool {
		return group[i][1] > group[j][1]
	})

	var ans [][]int
	for _, s := range group {
		var i int
		for i = 0; i < len(ans); i++ {
			if len(ans[i]) < s[1] {
				ans[i] = append(ans[i], s[0])
				break
			}
		}
		if i == len(ans) {
			ans = append(ans, []int{s[0]})
		}
	}

	return ans
}
