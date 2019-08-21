package main

import (
	"fmt"
	"sort"
)

func reconstructQueue(people [][]int) [][]int {
	sort.Slice(people, func(i, j int) bool {
		if people[i][0] == people[j][0] {
			return people[i][1] < people[j][1]
		}
		return people[i][0] < people[j][0]
	})

	q := make([][]int, len(people))
	for i := 0; i < len(people); i++ {
		cnt := people[i][1]
		for j := 0; j < len(people); j++ {
			if len(q[j]) == 0 {
				if cnt == 0 {
					q[j] = people[i]
					break
				} else {
					cnt--
				}
			} else {
				if q[j][0] >= people[i][0] {
					cnt--
				}
			}
		}
	}

	return q
}

func main() {
	people := [][]int{
		{7, 0},
		{4, 4},
		{7, 1},
		{5, 0},
		{6, 1},
		{5, 2},
	}

	q := reconstructQueue(people)
	fmt.Println(q)
}
