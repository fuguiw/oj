package main

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func minSteps(n int) int {
	if n == 1 {
		return 0
	}
	s := make([]int, n+1)
	for i := range s {
		s[i] = i
	}
	for i := 1; i <= n; i++ {
		for tmp := i + i; tmp <= n; tmp += i {
			s[tmp] = min(s[tmp], tmp/i+s[i])
		}
	}
	return s[n]
}
