package main

func secondHighest(s string) int {
	a, b := -1, -1
	for i := range s {
		if s[i] >= '0' && s[i] <= '9' {
			n := int(s[i] - '0')
			if n > a {
				a, b = n, a
			} else if n < a && n > b {
				b = n
			}
		}
	}
	return b
}
