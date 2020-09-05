package main

func diagonalSum(mat [][]int) int {
	ans := 0
	n := len(mat)

	for i := 0; i < n; i++ {
		ans += mat[i][i]
		if i != n-i-1 {
			ans += mat[i][n-i-1]
		}
	}

	return ans
}
