package main

func fib(N int) int {
	if N < 2 {
		return N
	}
	a, b, c := 0, 1, 0
	for i := 2; i <= N; i++ {
		c = a + b
		a, b = b, c
	}

	return c
}
