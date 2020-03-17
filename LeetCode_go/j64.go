package main

func sumNums(n int) int {
	var f func(*int, int) bool
	f = func(ans *int, n int) bool {
		*ans += n
		return n != 0 && f(ans, n-1)
	}

	ans := 0
	f(&ans, n)

	return ans
}
