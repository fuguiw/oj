package main

import "sort"

func getMaximumConsecutive(coins []int) int {
	sort.Ints(coins)
	m := 1
	for _, coin := range coins {
		if coin > m {
			return m
		}
		m += coin
	}

	return m
}
