package main

import (
	"container/list"
)

func Reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < len(r)/2; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

func reverseParentheses(s string) string {
	st := list.New()
	var str string
	for i := range s {
		if s[i] == '(' {
			st.PushBack(str)
			str = ""
		} else if s[i] == ')' {
			str = Reverse(str)
			str = st.Back().Value.(string) + str
			st.Remove(st.Back())
		} else {
			str += string(s[i])
		}
	}
	return str
}
