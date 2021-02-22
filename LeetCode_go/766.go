package main

func isToeplitzMatrix(matrix [][]int) bool {
	for i := range matrix {
		for j := range matrix[i] {
			if i > 0 && j > 0 {
				if matrix[i-1][j-1] != matrix[i][j] {
					return false
				}
			}
		}
	}

	return true
}
