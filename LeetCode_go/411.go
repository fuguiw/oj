package main

import "strconv"

func isAbbr(word, abbr string) bool {
	i, c := 0, 0
	for _, b := range []byte(abbr) {
		if b >= '0' && b <= '9' {
			c = c*10 + int(b-'0')
			continue
		}

		i += c
		if i >= len(word) || b != word[i] {
			return false
		}
		i, c = i+1, 0
	}

	return i+c == len(word)
}

func minAbbreviation(target string, dictionary []string) string {
	m := make([][]string, len(target))
	for i := 0; i < len(target); i++ {
		m[i] = []string{}
	}

	var f func(string, int, int)
	f = func(s string, i, c int) {
		if i == len(target) {
			if c > 0 {
				s += strconv.Itoa(c)
			}
			m[len(s)-1] = append(m[len(s)-1], s)
			return
		}

		f(s, i+1, c+1)
		if c > 0 {
			s += strconv.Itoa(c)
		}
		s += target[i : i+1]
		f(s, i+1, 0)
	}
	f("", 0, 0)

	for _, abbrs := range m {
		for _, abbr := range abbrs {
			i := 0
			for ; i < len(dictionary); i++ {
				if isAbbr(dictionary[i], abbr) {
					break
				}
			}
			if i == len(dictionary) {
				return abbr
			}
		}
	}
	return ""
}
