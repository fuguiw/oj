package main

import (
	"fmt"
	"sort"
)

func maximumNumberOfOnes(width int, height int, sideLength int, maxOnes int) int {
	matrix := make([][]int, height)
	for i := 0; i < height; i++ {
		matrix[i] = make([]int, width)
	}

	var nextPos [][]int
	for i := 0; i < sideLength; i++ {
		for j := 0; j < sideLength; j++ {
			nextPos = append(nextPos, []int{i, j})
		}
	}
	sort.Slice(nextPos, func(i, j int) bool {
		v1 := ((height-1-nextPos[i][0])/sideLength + 1) * ((width-1-nextPos[i][1])/sideLength + 1)
		v2 := ((height-1-nextPos[j][0])/sideLength + 1) * ((width-1-nextPos[j][1])/sideLength + 1)
		return v1 > v2
	})

	fmt.Println(nextPos)

	for maxOnes > 0 {
		i, j := nextPos[0][0], nextPos[0][1]

		for ti := i; ti < height; ti += sideLength {
			for tj := j; tj < width; tj += sideLength {
				matrix[ti][tj] = 1
			}
		}

		nextPos = nextPos[1:]
		maxOnes--
	}

	ans := 0
	for i := 0; i < height; i++ {
		for j := 0; j < width; j++ {
			ans += matrix[i][j]
		}
	}

	return ans
}
