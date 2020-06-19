package main

func generateParenthesis(n int) []string {
	var ans []string
	var f func(p string, l int, r int)
	f = func(p string, l int, r int) {
		if l < n {
			f(p+"(", l+1, r)
		}
		if r < l {
			f(p+")", l, r+1)
		}
		if l+r == n+n {
			ans = append(ans, p)
		}
	}
	f("", 0, 0)
	return ans
}
