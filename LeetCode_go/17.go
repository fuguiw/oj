package main

import "fmt"

var m map[byte]string

func find(digits string, idx int, str string, result *[]string) {
	if len(digits) == idx {
		*result = append(*result, str)
		return
	}

	s := m[digits[idx]]
	for i := 0; i < len(s); i++ {
		find(digits, idx+1, str+string(s[i]), result)
	}
}

func letterCombinations(digits string) []string {
	m = map[byte]string{
		'2': "abc",
		'3': "def",
		'4': "ghi",
		'5': "jkl",
		'6': "mno",
		'7': "pqrs",
		'8': "tuv",
		'9': "wxyz",
	}

	var result []string
	if len(digits) == 0 {
		return result
	}
	find(digits, 0, "", &result)
	return result
}
