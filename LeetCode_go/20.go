package main

import "container/list"

func isMatch(x, y byte) bool {
	if x == '(' && y == ')' {
		return true
	}
	if x == '[' && y == ']' {
		return true
	}
	if x == '{' && y == '}' {
		return true
	}
	return false
}

func isValid(s string) bool {
	st := list.New()

	for i := 0; i < len(s); i++ {
		if s[i] == '(' || s[i] == '[' || s[i] == '{' {
			st.PushBack(s[i])
		} else {
			if st.Len() != 0 && isMatch(st.Back().Value.(byte), s[i]) {
				st.Remove(st.Back())
			} else {
				return false
			}
		}
	}

	return st.Len() == 0
}
