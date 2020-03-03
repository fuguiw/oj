package main

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func spiralOrder(matrix [][]int) []int {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return nil
	}
	n := len(matrix)
	m := len(matrix[0])
	var ans []int

	for k := 0; k <= (min(n, m)-1)/2; k++ {
		for i, j := k, k; j < m-k; j++ {
			ans = append(ans, matrix[i][j])
		}
		for i, j := k+1, m-1-k; i < n-k; i++ {
			ans = append(ans, matrix[i][j])
		}
		for i, j := n-1-k, m-2-k; n-1-k != k && j >= k; j-- {
			ans = append(ans, matrix[i][j])
		}
		for i, j := n-2-k, k; m-1-k != k && i >= k+1; i-- {
			ans = append(ans, matrix[i][j])
		}
	}
	return ans
}
