package main

import "fmt"

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxSumDivThree(nums []int) int {
	m := make([]int, 4)
	tmp := make([]int, 4)
	for _, num := range nums {
		tmp[(0+num)%3] = max(tmp[(0+num)%3], m[0]+num)
		if m[1] != 0 {
			tmp[(1+num)%3] = max(tmp[(1+num)%3], m[1]+num)
		}
		if m[2] != 0 {
			tmp[(2+num)%3] = max(tmp[(2+num)%3], m[2]+num)
		}
		copy(m, tmp)
	}
	fmt.Println(m)

	return m[0]
}
