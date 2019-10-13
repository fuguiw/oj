package main

func searchMatrix(matrix [][]int, target int) bool {
	if len(matrix) == 0 {
		return false
	}

	for i, j := 0, len(matrix[0])-1; i >= 0 && i < len(matrix) && j >= 0 && j < len(matrix[i]); {
		if matrix[i][j] == target {
			return true
		} else if matrix[i][j] > target {
			j--
		} else {
			i++
		}
	}

	return false
}
