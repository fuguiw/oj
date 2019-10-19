package main

import "sort"

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func minAvailableDuration(slots1 [][]int, slots2 [][]int, duration int) []int {
	sort.Slice(slots1, func(i, j int) bool {
		return slots1[i][0] > slots1[j][0]
	})
	sort.Slice(slots2, func(i, j int) bool {
		return slots2[i][0] > slots2[j][0]
	})

	i, j := 0, 0
	for i < len(slots1) && j < len(slots2) {
		slot1, slot2 := slots1[i], slots2[j]

		begin := max(slot1[0], slot2[0])
		end := min(slot1[1], slot2[1])

		if end-begin >= duration {
			return []int{begin, begin + duration}
		}

		if slot1[0] > slot2[0] {
			j++
		} else {
			i++
		}
	}

	return []int{}
}
