package main

func minimumHammingDistance(source []int, target []int, allowedSwaps [][]int) int {
	fa := make([]int, 100001)
	for i := range fa {
		fa[i] = i
	}

	var find func(int) int
	find = func(x int) int {
		if fa[x] == x {
			return x
		}
		return find(fa[x])
	}

	merge := func(i, j int) {
		fa[find(i)] = find(j)
	}

	for _, swap := range allowedSwaps {
		merge(swap[0], swap[1])
	}

	m := make(map[int][]int)
	visit := make(map[int]bool)

	for _, swap := range allowedSwaps {
		for i := range swap {
			f := find(swap[i])
			if f != swap[i] {
				m[f] = append(m[f], swap[i])
			}
		}
	}

	ans := 0
	for k, v := range m {
		v = append(v, k)
		var arr []int
		e := make(map[int]int)
		for _, i := range v {
			if visit[i] == false {
				arr = append(arr, i)
				e[source[i]]++
			}
			visit[i] = true
		}
		for _, i := range arr {
			if e[target[i]] <= 0 {
				ans++
			} else {
				e[target[i]]--
			}
		}
	}

	for i := range source {
		if visit[i] == false && source[i] != target[i] {
			ans++
		}
	}

	return ans
}
