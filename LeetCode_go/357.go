package main

func countNumbersWithUniqueDigits(n int) int {
	if n == 0 {
		return 1
	}
	d := make([]int, 11)
	d[1] = 10
	for i, c := 2, 9; i < 11; i++ {
		c *= 11 - i
		d[i] = c
	}

	ans := 0
	for i := 1; i <= n; i++ {
		ans += d[i]
	}

	return ans
}
