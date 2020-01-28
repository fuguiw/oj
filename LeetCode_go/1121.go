package main

func canDivideIntoSubsequences(nums []int, K int) bool {
	m := make(map[int]int)

	for _, n := range nums {
		m[n]++
		if len(nums)/m[n] < K {
			return false
		}
	}

	return true
}
