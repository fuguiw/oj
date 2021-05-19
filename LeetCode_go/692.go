package main

import "sort"

func topKFrequent(words []string, k int) []string {
	m := map[string]int{}

	for _, word := range words {
		m[word]++
	}

	nodes := make([]string, 0, len(words))
	for word, _ := range m {
		nodes = append(nodes, word)
	}
	sort.Slice(nodes, func(i, j int) bool {
		s, t := nodes[i], nodes[j]
		return m[s] > m[t] || m[s] == m[t] && s < t
	})

	return nodes[:k]
}
