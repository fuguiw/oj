package main

func setZeroes(matrix [][]int) {
	n := len(matrix)
	if n == 0 {
		return
	}
	m := len(matrix[0])

	row, col := 1, 1
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if matrix[i][j] == 0 {
				if i == 0 {
					row = 0
				}
				if j == 0 {
					col = 0
				}
				if i != 0 && j != 0 {
					matrix[i][0], matrix[0][j] = 0, 0
				}
			}
		}
	}
	for i := 1; i < n; i++ {
		if matrix[i][0] == 0 {
			for j := 1; j < m; j++ {
				matrix[i][j] = 0
			}
		}
	}
	for i := 1; i < n; i++ {
		if matrix[i][0] == 0 {
			for j := 1; j < m; j++ {
				matrix[i][j] = 0
			}
		}
	}
	for i := 1; i < m; i++ {
		if matrix[0][i] == 0 {
			for j := 1; j < n; j++ {
				matrix[j][i] = 0
			}
		}
	}
	if row == 0 {
		for i := 0; i < m; i++ {
			matrix[0][i] = 0
		}
	}
	if col == 0 {
		for i := 0; i < n; i++ {
			matrix[i][0] = 0
		}
	}
}
