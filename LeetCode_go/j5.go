package main

func replaceSpace(s string) string {
	l := len(s)
	for i := 0; i < l; i++ {
		if s[i] == ' ' {
			s = s[:i] + "%20" + s[i+1:]
			l += 2
		}
	}
	return s
}
