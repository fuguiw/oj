package main

func setZeroes(matrix [][]int) {
	r, c := false, false
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[i]); j++ {
			if matrix[i][j] == 0 {
				matrix[0][j], matrix[i][0] = 0, 0
				if i == 0 {
					r = true
				}
				if j == 0 {
					c = true
				}
			}
		}
	}

	for i := len(matrix) - 1; i >= 0; i-- {
		for j := len(matrix[i]) - 1; j >= 0; j-- {
			if matrix[i][0] == 0 || matrix[0][j] == 0 {
				if i == 0 && r == false || j == 0 && c == false {
					continue
				}
				matrix[i][j] = 0
			}
		}
	}
}
