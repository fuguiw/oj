package main

import "fmt"

func isPalindrome(s string) bool {
	n := len(s)
	for i := 0; i <= n/2; i++ {
		if s[i] != s[n-i-1] {
			return false
		}
	}
	return true
}

func partition(s string) [][]string {
	var ans [][]string

	var find func([]string, int)
	find = func(p []string, i int) {
		if i == len(s) {
			ss := make([]string, len(p))
			copy(ss, p)
			ans = append(ans, ss)
		}

		var str []byte
		for ; i < len(s); i++ {
			str = append(str, s[i])
			if isPalindrome(string(str)) {
				p = append(p, string(str))
				find(p, i+1)
				p = p[:len(p)-1]
			}
		}
	}

	var p []string
	find(p, 0)

	return ans
}
