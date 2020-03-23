package main

import (
	"strings"
)

func wordBreak(s string, wordDict []string) bool {
	d := make([][]bool, len(s))
	for i := range d {
		d[i] = make([]bool, len(s))
	}

	for _, word := range wordDict {
		idx := strings.Index(s, word)
		for pos := 0; idx != -1; {
			d[pos+idx][pos+idx+len(word)-1] = true
			pos += idx + 1
			idx = strings.Index(s[pos:], word)
		}
	}

	for i := 0; i < len(s); i++ {
		for j := i + 1; j < len(s); j++ {
			for k := i; k < j; k++ {
				d[i][j] = d[i][j] || (d[i][k] && d[k+1][j])
			}
		}
	}

	return d[0][len(s)-1]
}
