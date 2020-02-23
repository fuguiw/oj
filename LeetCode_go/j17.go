package main

import "math"

func printNumbers(n int) []int {
	c := int(math.Pow10(n))
	var ans []int
	for i := 1; i < c; i++ {
		ans = append(ans, i)
	}
	return ans
}
