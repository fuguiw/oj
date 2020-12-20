package main

import (
	"math"
	"sort"
)

type node struct {
	i   int
	num int
}

func smallestRange(nums [][]int) []int {
	var nodes []node
	for j := range nums {
		for k := range nums[j] {
			nodes = append(nodes, node{j, nums[j][k]})
		}
	}

	sort.Slice(nodes, func(i, j int) bool {
		return nodes[i].num < nodes[j].num
	})

	ans := []int{0, math.MaxInt32}
	n := len(nums)
	count := 0
	m := make(map[int]int)
	for begin, end := 0, 0; end < len(nodes); end++ {
		m[nodes[end].i]++
		if m[nodes[end].i] == 1 {
			count++
		}

		for count == n {
			if nodes[end].num-nodes[begin].num < ans[1]-ans[0] {
				ans[0], ans[1] = nodes[begin].num, nodes[end].num
			}
			m[nodes[begin].i]--
			if m[nodes[begin].i] == 0 {
				count--
			}
			begin++
		}
	}

	return ans
}
