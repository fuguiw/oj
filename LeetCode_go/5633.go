package main

func totalMoney(n int) int {
	if n == 0 {
		return 0
	}
	w := (n - 1) / 7
	d := ((n - 1) % 7) + 1
	return totalMoney(n-1) + w + d
}
