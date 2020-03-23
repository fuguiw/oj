package main

func wordBreak(s string, wordDict []string) bool {
	m := make(map[string]bool)
	for _, word := range wordDict {
		m[word] = true
	}

	d := make([]bool, len(s)+1)
	d[0] = true
	for i := 0; i <= len(s); i++ {
		for j := 0; j < i; j++ {
			if _, ok := m[s[j:i]]; ok && d[j] {
				d[i] = true
			}
		}
	}

	return d[len(s)]
}
