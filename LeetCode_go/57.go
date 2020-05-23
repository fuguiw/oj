package main

func insert(intervals [][]int, newInterval []int) [][]int {
	var ans [][]int
	for i, c := 0, 0; c <= len(intervals); c++ {
		tmp := newInterval
		if i < c || (i < len(intervals) && intervals[i][0] < tmp[0]) {
			tmp = intervals[i]
			i++
		}

		j := len(ans) - 1
		if j == -1 || ans[j][1] < tmp[0] {
			ans = append(ans, tmp)
			continue
		}

		if ans[j][1] < tmp[1] {
			ans[j][1] = tmp[1]
		}
	}

	return ans
}
