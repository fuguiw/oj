package main

import (
	"math"
)

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func findCheapestPrice(n int, flights [][]int, src int, dst int, K int) int {
	dis := make([][]int, n)
	for i := range dis {
		dis[i] = make([]int, n)
		for j := range dis[i] {
			dis[i][j] = math.MaxInt32
		}
		dis[i][src] = 0
	}

	for k := 0; k <= K; k++ {
		for _, flight := range flights {
			if k == 0 {
				if flight[0] == src {
					dis[k][flight[1]] = flight[2]
				}
				continue
			}
			dis[k][flight[1]] = min(dis[k][flight[1]], dis[k-1][flight[0]]+flight[2])
		}
	}

	if dis[K][dst] == math.MaxInt32 {
		return -1
	}
	return dis[K][dst]
}
