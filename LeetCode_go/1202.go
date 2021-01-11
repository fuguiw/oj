package main

import "sort"

func smallestStringWithSwaps(s string, pairs [][]int) string {
	n := len(s)
	f := make([]int, 1e5+1)
	for i := range f {
		f[i] = i
	}

	var find func(int) int
	find = func(x int) int {
		if f[x] != x {
			f[x] = find(f[x])
		}
		return f[x]
	}

	merge := func(x, y int) {
		f[find(y)] = find(x)
	}

	for _, pair := range pairs {
		merge(pair[0], pair[1])
	}

	pos := make([][]int, n)
	for i := range s {
		pos[find(i)] = append(pos[find(i)], i)
	}

	ans := make([]byte, n)
	for i := range s {
		if len(pos[i]) == 0 {
			continue
		}
		var str []byte
		var idx []int
		for _, x := range pos[i] {
			idx = append(idx, x)
			str = append(str, s[x])
		}
		sort.Ints(idx)
		sort.Slice(str, func(i, j int) bool {
			return str[i] < str[j]
		})
		for i := range idx {
			ans[idx[i]] = str[i]
		}
	}

	return string(ans)
}
