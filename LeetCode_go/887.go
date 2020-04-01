package main

import "math"

func max(x ,y int) int {
	if x > y {
		return x
	}
	return y
}
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func superEggDrop(K int, N int) int {
	m := make(map[int]int)

	var dp func(k, n int) int
	dp = func(k, n int) int {
		if n == 0 {
			return 0
		}
		if k == 1 {
			return n
		}

		if _, ok := m[n * 100 + k]; ok {
			return m[n * 100 + k]
		}

		ans := math.MaxInt32
		for i := 1; i <= n + 1; i++ {
			ans = min(ans, max(dp(k - 1, i - 1), dp(k, n - i)) + 1)
		}

		m[n * 100 + k] = ans
		return ans
	}
	return dp(K,N)
}
