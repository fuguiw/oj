package main

import "sort"

func topKFrequent(words []string, k int) []string {
	m := map[string]int{}

	for _, word := range words {
		m[word]++
	}

	type node struct {
		word  string
		count int
	}

	nodes := make([]node, 0, len(words))
	for k, v := range m {
		nodes = append(nodes, node{k, v})
	}
	sort.Slice(nodes, func(i, j int) bool {
		if nodes[i].count == nodes[j].count {
			return nodes[i].word < nodes[j].word
		}
		return nodes[i].count > nodes[j].count
	})

	ans := make([]string, 0, k)
	for i := 0; i < k; i++ {
		ans = append(ans, nodes[i].word)
	}
	return ans
}
