package main

type unionFind struct {
	fa  []int
	cnt int
}

func newUnion(n int) *unionFind {
	uf := &unionFind{cnt: n}
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
	uf.cnt--
}

func maxNumEdgesToRemove(n int, edges [][]int) int {
	ufa, ufb := newUnion(n), newUnion(n)

	ans := 0
	for _, edge := range edges {
		if edge[0] == 3 {
			a, b := edge[1], edge[2]
			if ufa.find(a) == ufa.find(b) {
				ans++
				continue
			}
			ufa.merge(a, b)
			ufb.merge(a, b)
		}
	}

	for _, edge := range edges {
		a, b := edge[1], edge[2]
		if edge[0] == 1 {
			if ufa.find(a) == ufa.find(b) {
				ans++
			} else {
				ufa.merge(a, b)
			}
		}
		if edge[0] == 2 {
			if ufb.find(a) == ufb.find(b) {
				ans++
			} else {
				ufb.merge(a, b)
			}
		}
	}

	if ufa.cnt != 1 || ufb.cnt != 1 {
		return -1
	}

	return ans
}
