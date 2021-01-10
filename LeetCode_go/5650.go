package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func minimumHammingDistance(source []int, target []int, allowedSwaps [][]int) int {
	fa := make([]int, 1e5+1)
	for i := range fa {
		fa[i] = i
	}

	var find func(int) int
	find = func(x int) int {
		if fa[x] != x {
			fa[x] = find(fa[x])
		}
		return fa[x]
	}

	merge := func(i, j int) {
		fa[find(i)] = find(j)
	}

	for _, swap := range allowedSwaps {
		merge(swap[0], swap[1])
	}

	n := len(source)
	d := make([][]int, n)
	for i := range source {
		f := find(i)
		d[f] = append(d[f], i)
	}

	ans := 0
	for i := range source {
		if len(d[i]) == 0 {
			continue
		}
		A, B := make(map[int]int), make(map[int]int)
		for _, x := range d[i] {
			A[source[x]]++
			B[target[x]]++
		}
		for k := range B {
			ans += max(0, B[k]-A[k])
		}
	}

	return ans
}
