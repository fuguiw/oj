package main

func findRepeatNumber(nums []int) int {
	m := make([]int, len(nums))
	for _, n := range nums {
		if m[n] == 1 {
			return n
		}
		m[n] = 1
	}
	return 0
}
