package main

import "math"

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func nearestValidPoint(x int, y int, points [][]int) int {
	ans := -1
	dis := math.MaxInt32
	for i, point := range points {
		if point[0] == x || point[1] == y {
			if abs(x-point[0])+abs(y-point[1]) < dis {
				ans = i
				dis = abs(x-point[0]) + abs(y-point[1])
			}
		}
	}
	return ans
}
