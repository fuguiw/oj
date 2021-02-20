package main

func isGood(s string) bool {
	m := make(map[byte]int)
	for i := range s {
		m[s[i]]++
	}

	for i := range s {
		if s[i] >= 'a' && s[i] <= 'z' {
			if _, ok := m[s[i]+'A'-'a']; !ok {
				return false
			}
		}
		if s[i] >= 'A' && s[i] <= 'Z' {
			if _, ok := m[s[i]+'a'-'A']; !ok {
				return false
			}
		}
	}
	return true
}

func longestNiceSubstring(s string) string {
	var ans string
	for right := len(s) - 1; right >= 0; right-- {
		for left := 0; left < right; left++ {
			str := s[left : right+1]
			if isGood(str) && len(ans) <= len(str) {
				ans = str
			}
		}
	}

	return ans
}
