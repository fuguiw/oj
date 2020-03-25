package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func maximalRectangle(matrix [][]byte) int {
	if len(matrix) == 0 {
		return 0
	}
	n := len(matrix)
	m := len(matrix[0])
	height := make([]int, m)
	left := make([]int, m)
	right := make([]int, m)
	ans := 0
	for i := 0; i < m; i++ {
		right[i] = m
	}

	for i := 0; i < n; i++ {
		curLeft, curRight := 0, m
		for j := 0; j < m; j++ {
			if matrix[i][j] == '1' {
				height[j]++
				left[j] = max(left[j], curLeft)
			} else {
				height[j], left[j] = 0, 0
				curLeft = j + 1
			}
		}

		for j := m - 1; j >= 0; j-- {
			if matrix[i][j] == '1' {
				right[j] = min(right[j], curRight)
			} else {
				right[j] = n
				curRight = j
			}
		}

		for j := 0; j < m; j++ {
			ans = max(ans, (right[j]-left[j])*height[j])
		}
	}

	return ans
}
