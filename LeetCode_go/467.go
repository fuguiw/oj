package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func findSubstringInWraproundString(p string) int {
	dp := make([]int, 26)

	c := 0
	for i := range p {
		if i > 0 && (p[i-1]-'a') == ((p[i]-'a'+25)%26) {
			c++
		} else {
			c = 1
		}
		dp[p[i]-'a'] = max(dp[p[i]-'a'], c)
	}

	ans := 0
	for _, d := range dp {
		ans += d
	}
	return ans
}
