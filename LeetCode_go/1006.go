package main

func clumsy(N int) int {
	calc := func(n int) int {
		ans := n
		if n > 1 {
			ans *= (n - 1)
		}
		if n > 2 {
			ans /= (n - 2)
		}

		return ans
	}

	ans := calc(N)
	N -= 2
	for N > 0 {
		ans += N - calc(N-1)
		N -= 3
	}
	return ans
}
