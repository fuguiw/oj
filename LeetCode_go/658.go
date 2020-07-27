package main

import (
	"fmt"
	"sort"
)

func findClosestElements(arr []int, k int, x int) []int {
	i := sort.SearchInts(arr, x)
	if i == len(arr) || (arr[i] > x && i > 0) {
		i--
	}
	var ans []int
	for l, r := i, i+1; k > 0; k-- {
		fmt.Println(l, arr[l])
		fmt.Println(r, arr[r])
		if r >= len(arr) || (l >= 0 && (x-arr[l]) <= (arr[r]-x)) {
			ans = append(ans, arr[l])
			l--
		} else {
			ans = append(ans, arr[r])
			r++
		}
	}

	sort.Ints(ans)
	return ans
}
