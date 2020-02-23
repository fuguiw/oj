package main

const mod int64 = 1000000007

func cuttingRope(n int) int {
	if n <= 3 {
		return n - 1
	}

	var ans int64 = 1
	for n > 4 {
		ans = ans * 3 % mod
		n -= 3
	}

	return int(ans * int64(n) % mod)
}
