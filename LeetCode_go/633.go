package main

import (
	"fmt"
	"math"
)

func judgeSquareSum(c int) bool {
	right := int(math.Sqrt(float64(c)))

	for left := 0; left <= right; {
		s := left*left + right*right
		if s == c {
			return true
		}
		if s < c {
			left++
		} else {
			right--
		}
	}
	return false
}
