package main

func flipAndInvertImage(A [][]int) [][]int {
	for _, row := range A {
		for left, right := 0, len(row)-1; left <= right; left, right = left+1, right-1 {
			row[left], row[right] = 1-row[right], 1-row[left]
		}
	}

	return A
}
