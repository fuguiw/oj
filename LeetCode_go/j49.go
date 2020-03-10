package main

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func nthUglyNumber(n int) int {
	p2, p3, p5 := 0, 0, 0
	d := make([]int, n)
	d[0] = 1

	for i := 1; i < n; i++ {
		d[i] = min(d[p2]*2, min(d[p3]*3, d[p5]*5))
		if d[i] == d[p2]*2 {
			p2++
		}
		if d[i] == d[p3]*3 {
			p3++
		}
		if d[i] == d[p5]*5 {
			p5++
		}
	}
	return d[n-1]
}
