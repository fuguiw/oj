package main

import "sort"

func numRescueBoats(people []int, limit int) int {
	ans := 0

	sort.Slice(people, func(i, j int) bool {
		return people[i] > people[j]
	})

	for b, s := 0, len(people)-1; b <= s; {
		if people[b]+people[s] <= limit {
			b++
			s--
		} else {
			b++
		}
		ans++
	}

	return ans
}
