package main

import (
	"fmt"
	"math"
)

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func findLengthOfShortestSubarray(arr []int) int {
	n := len(arr)
	ans := math.MaxInt32
	var i int
	for i = 1; i < n; i++ {
		if arr[i] < arr[i-1] {
			break
		}
	}
	fmt.Println(i)
	ans = min(ans, n-i)

	var j int
	for j = n - 2; j >= 0; j-- {
		if arr[j+1] < arr[j] {
			break
		}
	}
	fmt.Println(j)
	ans = min(ans, j+1)

	if ans == 0 {
		return ans
	}

	for x := i - 1; x >= 0; x-- {
		for y := j + 1; y < n; y++ {
			if arr[y] >= arr[x] {
				fmt.Println(x, y)
				ans = min(ans, y-x-1)
				break
			}
		}
	}

	return ans
}
