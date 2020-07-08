package main

import "fmt"

func subsets(nums []int) [][]int {
	var ans [][]int
	ans = append(ans, []int{})

	for _, num := range nums {
		n := len(ans)
		for i := 0; i < n; i++ {
			ans = append(ans, make([]int, len(ans[i])+1))
			copy(ans[len(ans)-1], append(ans[i], num))
			fmt.Println(ans[i], num)
			fmt.Println(ans)
		}
	}
	return ans
}
