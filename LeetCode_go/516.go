package main

import "fmt"

func longestPalindromeSubseq(s string) int {
	d := make([][]int, len(s))
	for i := 0; i < len(d); i++ {
		d[i] = make([]int, len(s))
	}

	for i := len(s) - 1; i >= 0; i-- {
		d[i][i] = 1
		for j := i + 1; j < len(s); j++ {
			if s[i] == s[j] {
				d[i][j] = d[i+1][j-1] + 2
			} else {
				if d[i+1][j] > d[i][j-1] {
					d[i][j] = d[i+1][j]
				} else {
					d[i][j] = d[i][j-1]
				}
			}
		}
	}

	return d[0][len(s)-1]
}

func main() {
	s := "bbbab"
	fmt.Println(longestPalindromeSubseq(s))
}
