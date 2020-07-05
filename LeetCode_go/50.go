package main

func myPow(x float64, n int) float64 {
	if n == 1 {
		return x
	}
	if n == 0 {
		return 1
	}
	if n < 0 {
		return 1 / myPow(x, -n)
	}

	tmp := myPow(x, n/2)
	ans := tmp * tmp
	if n%2 == 1 {
		ans *= x
	}

	return ans
}
