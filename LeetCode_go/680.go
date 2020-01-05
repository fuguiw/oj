package main

import "fmt"

func isPalindrome(s string, begin, end int) bool {
	for begin < end {
		if s[begin] != s[end] {
			return false
		}
		begin++
		end--
	}
	return true
}

func validPalindrome(s string) bool {
	left, right := 0, len(s)-1
	for left < right {
		if s[left] != s[right] {
			if isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1) {
				return true
			} else {
				return false
			}
		}
		left++
		right--
	}

	return true
}
