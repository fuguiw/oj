package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxUncrossedLines(A []int, B []int) int {
	n, m := len(A), len(B)
	d := make([][]int, n+1)
	for i := range d {
		d[i] = make([]int, m+1)
	}

	ans := 0
	for i := range A {
		for j := range B {
			if A[i] == B[j] {
				d[i+1][j+1] = d[i][j] + 1
			} else {
				d[i+1][j+1] = max(d[i][j], max(d[i][j+1], d[i+1][j]))
			}
			ans = max(ans, d[i+1][j+1])
		}
	}
	return ans
}
