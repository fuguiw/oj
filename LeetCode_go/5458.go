package main

func numSplits(s string) int {
	p, q := make(map[uint8]int), make(map[uint8]int)

	for i := range s {
		q[s[i]]++
	}

	var getCount = func(m map[uint8]int) int {
		count := 0
		var c uint8
		for c = 'a'; c <= 'z'; c++ {
			if m[c] > 0 {
				count++
			}
		}
		return count
	}

	ans := 0
	for i := 0; i < len(s); i++ {
		p[s[i]]++
		q[s[i]]--
		if getCount(p) == getCount(q) {
			ans++
		}
	}
	return ans
}
