package main

import (
	"strings"
)

func boldWords(words []string, S string) string {
	l := len(S)
	d := make([]int, l)
	for _, word := range words {
		for i := 0; i != -1; {
			j := strings.Index(S[i:], word)
			if j == -1 {
				break
			}
			j += i
			for i = j; i < j+len(word); i++ {
				d[i] = 1
			}
			i = j + 1
		}
	}

	var ans string
	var i, j int
	for i, j = 0, 0; j <= l; j++ {
		if j == l || d[j] == 0 {
			if i != j {
				if len(ans) == 0 {
					ans = S[:i]
				}
				ans += "<b>" + S[i:j] + "</b>"
			}
			if j < l {
				ans += S[j : j+1]
			}
			i = j + 1
		}
	}

	return ans
}
