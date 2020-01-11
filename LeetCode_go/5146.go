package main

func distinctEchoSubstrings(text string) int {
	t := []byte(text)
	m := make(map[string]int)

	ans := 0
	for i := 1; i < len(text)/2; i++ {
		tt := t[i:]
		b := 0
		for j := 0; j < len(tt); j++ {
			if t[j] != tt[j] {
				b = j + 1
			} else {
				if j-b+1 == i {
					m[string(t[b:j+1])]++
					if m[string(t[b:j+1])] == 1 {
						ans++
					}
					b++
				}
			}
		}
	}

	return ans
}
