package main

import "sort"

const L = 30

type trie struct {
	children [2]*trie
}

func (t *trie) insert(val int) {
	node := t
	for i := L - 1; i >= 0; i-- {
		bit := val >> i & 1
		if node.children[bit] == nil {
			node.children[bit] = &trie{}
		}
		node = node.children[bit]
	}
}

func (t *trie) getMaxXor(val int) int {
	ans := 0
	node := t
	for i := L - 1; i >= 0; i-- {
		bit := val >> i & 1
		if node.children[bit^1] != nil {
			ans |= 1 << i
			bit ^= 1
		}
		node = node.children[bit]
	}

	return ans
}

func maximizeXor(nums []int, queries [][]int) []int {
	sort.Ints(nums)
	for i := range queries {
		queries[i] = append(queries[i], i)
	}
	sort.Slice(queries, func(i, j int) bool {
		return queries[i][1] < queries[j][1]
	})

	t := &trie{}
	i := 0
	ans := make([]int, len(queries))
	for _, query := range queries {
		x, m, idx := query[0], query[1], query[2]
		for i < len(nums) && nums[i] <= m {
			t.insert(nums[i])
			i++
		}
		if i == 0 {
			ans[idx] = -1
		} else {
			ans[idx] = t.getMaxXor(x)
		}
	}

	return ans
}
