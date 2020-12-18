package main

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func enough(x int, m int, n int, k int) bool {
	count := 0
	for i := 1; i <= m; i++ {
		count += min(x/i, n)
	}

	return count >= k
}

func findKthNumber(m int, n int, k int) int {
	lo, hi := 1, n*m
	for lo <= hi {
		mid := (lo + hi) / 2
		if enough(mid, n, m, k) {
			hi = mid
		} else {
			lo = mid + 1
		}
	}

	return lo
}
