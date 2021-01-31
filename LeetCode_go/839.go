package main

func isSimilar(X, Y string) bool {
	cnt := 0
	var x, y int
	for i := range X {
		if X[i] == Y[i] {
			continue
		}
		cnt++
		if cnt == 1 {
			x = i
		} else if cnt == 2 {
			y = i
		} else {
			return false
		}
	}

	if cnt == 0 || (cnt == 2 && Y[x] == X[y] && Y[y] == X[x]) {
		return true
	}
	return false
}

type unionFind struct {
	fa []int
}

func newUnion(n int) *unionFind {
	uf := &unionFind{}
	uf.fa = make([]int, n+1)
	for i := range uf.fa {
		uf.fa[i] = i
	}
	return uf
}

func (uf *unionFind) find(x int) int {
	if uf.fa[x] != x {
		uf.fa[x] = uf.find(uf.fa[x])
	}
	return uf.fa[x]
}

func (uf *unionFind) merge(x, y int) {
	uf.fa[uf.find(y)] = uf.find(x)
}

func numSimilarGroups(strs []string) int {
	n := len(strs)
	uf := newUnion(n)

	for i, str := range strs {
		for j := i - 1; j >= 0; j-- {
			if isSimilar(strs[j], str) {
				uf.merge(i, j)
			}
		}
	}

	ans := 0
	for i := range strs {
		if uf.find(i) == i {
			ans++
		}
	}
	return ans
}
