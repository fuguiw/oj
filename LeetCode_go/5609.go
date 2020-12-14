package main

func countConsistentStrings(allowed string, words []string) int {
	m := make(map[byte]bool)

	for i := range allowed {
		m[allowed[i]] = true
	}

	ans := 0
	for _, word := range words {
		for i := range word {
			if _, ok := m[word[i]]; !ok {
				ans--
				break
			}
		}
		ans++
	}
	return ans
}
