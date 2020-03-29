package main

func find(s string, isP [][]int, begin, end int) int {
	if begin > end {
		return 1
	}
	if isP[begin][end] != 0 {
		return isP[begin][end]
	}

	if s[begin] == s[end] {
		isP[begin][end] = find(s, isP, begin+1, end-1)
	} else {
		isP[begin][end] = -1
	}

	return isP[begin][end]
}

func countSubstrings(s string) int {
	isP := make([][]int, len(s))
	for i := 0; i < len(s); i++ {
		isP[i] = make([]int, len(s))
	}

	result := len(s)
	for i := len(s) - 1; i >= 0; i-- {
		for j := i + 1; j < len(s); j++ {
			if find(s, isP, i, j) == 1 {
				result++
			}
		}
	}

	return result
}
