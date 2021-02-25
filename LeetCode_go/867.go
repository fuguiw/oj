package main

func transpose(A [][]int) [][]int {
	n, m := len(A), len(A[0])

	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
	}

	for i := range A {
		for j := range A[i] {
			ans[j][i] = A[i][j]
		}
	}
	return ans
}
