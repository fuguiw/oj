package main

import (
	"strconv"
	"strings"
)

func encode(s string) string {
	d := make([][]string, len(s)+1)
	for i := 0; i < len(d); i++ {
		d[i] = make([]string, len(s)+1)
	}

	for l := 1; l <= len(s); l++ {
		for i := 0; i+l <= len(s); i++ {
			j := i + l
			d[i][j] = s[i:j]
			if len(d[i][j]) >= 5 {
				p := strings.Index((d[i][j] + d[i][j])[1:], d[i][j]) + 1
				if p > 0 && p < len(d[i][j]) {
					d[i][j] = strconv.Itoa(len(d[i][j])/p) + "[" + d[i][i+p] + "]"
				}
				for k := i + 1; k < j; k++ {
					if len(d[i][k])+len(d[k][j]) < len(d[i][j]) {
						d[i][j] = d[i][k] + d[k][j]
					}
				}
			}
		}
	}

	return d[0][len(s)]
}
