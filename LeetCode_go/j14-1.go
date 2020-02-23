package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func find(m []int, n int) int {
	if m[n] != 0 {
		return m[n]
	}
	ans := 0
	for i := 1; i <= n/2; i++ {
		ans = max(ans, max(i, find(m, i))*max(n-i, find(m, n-i)))
	}
	m[n] = ans
	return ans
}

func cuttingRope(n int) int {
	m := make([]int, n+1)
	return find(m, n)
}
