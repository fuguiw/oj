package main

func monotoneIncreasingDigits(N int) int {
	p := 1
	pre := 9
	ans := 0
	for N/p > 0 {
		cur := N / p % 10
		if cur > pre {
			cur--
			ans = p - 1
		}
		pre = cur
		ans += cur * p
		p *= 10
	}

	return ans
}
