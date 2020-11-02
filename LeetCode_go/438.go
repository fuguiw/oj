package main

import "reflect"

func findAnagrams(s string, p string) []int {
	mp := make(map[byte]int)
	for i := range p {
		mp[p[i]]++
	}

	var ans []int
	ms := make(map[byte]int)
	for start, end := 0, 0; end < len(s); end++ {
		ms[s[end]]++
		if end-start+1 == len(p) {
			if reflect.DeepEqual(ms, mp) {
				ans = append(ans, start)
			}
			ms[s[start]]--
			if ms[s[start]] == 0 {
				delete(ms, s[start])
			}
			start++
		}
	}
	return ans
}
