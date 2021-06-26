package main

import "strings"

func removeOccurrences(s string, part string) string {
	idx := strings.Index(s, part)
	for idx != -1 {
		s = strings.Replace(s, part, "", 1)
		idx = strings.Index(s, part)
	}
	return s
}
