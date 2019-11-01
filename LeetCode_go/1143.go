package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func longestCommonSubsequence(text1 string, text2 string) int {
	result := 0
	d := make([][]int, len(text1))
	for i := 0; i < len(text1); i++ {
		d[i] = make([]int, len(text2))
	}

	for i := 0; i < len(text1); i++ {
		for j := 0; j < len(text2); j++ {
			if text1[i] == text2[j] {
				d[i][j] = 1
				if i > 0 && j > 0 {
					d[i][j] = d[i-1][j-1] + 1
				}
			} else {
				if i > 0 {
					d[i][j] = max(d[i][j], d[i-1][j])
				}
				if j > 0 {
					d[i][j] = max(d[i][j], d[i][j-1])
				}
			}
			result = max(result, d[i][j])
		}
	}
	return result
}
