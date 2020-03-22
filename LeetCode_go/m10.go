package main

func minWindow(s string, t string) string {
	tm := make(map[byte]int)
	ans := ""
	for i := range t {
		tm[t[i]]++
	}

	m := make(map[byte]int)
	c := 0
	for begin, end := 0, 0; end <= len(s); {
		if c == len(t) {
			if len(ans) == 0 || len(ans) > end-begin {
				ans = s[begin:end]
			}
			if tm[s[begin]] >= 1 {
				m[s[begin]]--
				if m[s[begin]] < tm[s[begin]] {
					c--
				}
			}
			begin++
		} else {
			if end < len(s) && tm[s[end]] >= 1 {
				m[s[end]]++
				if m[s[end]] <= tm[s[end]] {
					c++
				}
			}
			end++
		}
	}

	return ans
}
