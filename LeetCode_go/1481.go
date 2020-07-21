package main

import "sort"

func findLeastNumOfUniqueInts(arr []int, k int) int {
	m := make(map[int]int)
	for _, num := range arr {
		m[num]++
	}
	var v [][]int
	for key, value := range m {
		v = append(v, []int{key, value})
	}
	sort.Slice(v, func(i, j int) bool {
		return v[i][1] < v[j][1]
	})

	ans := len(v)
	for i := 0; i < len(v) && k >= v[i][1]; i++ {
		ans--
		k -= v[i][1]
	}
	return ans
}
