package main

func isPalindrome(s string) bool {
	for i, j := 0, len(s)-1; i < j; {
		a := s[i]
		if a >= '0' && a <= '9' || a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z' {
			if a >= 'A' && a <= 'Z' {
				a = a + 'a' - 'A'
			}
		} else {
			i++
			continue
		}

		b := s[j]
		if b >= '0' && b <= '9' || b >= 'a' && b <= 'z' || b >= 'A' && b <= 'Z' {
			if b >= 'A' && b <= 'Z' {
				b = b + 'a' - 'A'
			}
		} else {
			j--
			continue
		}

		if a != b {
			return false
		} else {
			i++
			j--
		}
	}

	return true
}
