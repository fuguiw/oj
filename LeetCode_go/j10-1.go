package main

const mod int = 1000000007

func fib(n int) int {
	if n == 0 || n == 1 {
		return n
	}

	a, b, c := 0, 1, 0
	for i := 2; i <= n; i++ {
		c = (a%mod + b%mod) % mod
		a, b = b, c
	}

	return c
}
