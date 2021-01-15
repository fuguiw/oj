package main

import "fmt"

func sortItems(n int, m int, group []int, beforeItems [][]int) []int {
	gnext := make([][]int, m+1)
	next := make([][]int, n)

	for i, items := range beforeItems {
		for _, item := range items {
			next[item] = append(next[item], i)
			if group[item] != group[i] {
				gnext[group[item]] = append(gnext[group[item]], i)
			}
		}
	}

	fmt.Println(gnext, next)
	var ans []int

	return ans
}
