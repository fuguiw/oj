package main

func dfs(tree [][]int, vis []int, curr int, l int, target *int, ll *int) {
	if l > *ll {
		*ll = l
		*target = curr
	}
	vis[curr] = 1
	for i := 0; i < len(tree[curr]); i++ {
		if vis[tree[curr][i]] == 1 {
			continue
		}
		dfs(tree, vis, tree[curr][i], l+1, target, ll)
		//vis[curr][tree[curr][i]] = 0
	}
}

func treeDiameter(edges [][]int) int {
	tree := make([][]int, len(edges)+1)
	for _, edge := range edges {
		tree[edge[0]] = append(tree[edge[0]], edge[1])
		tree[edge[1]] = append(tree[edge[1]], edge[0])
	}

	vis := make([]int, len(edges)+1)

	target, ll := 0, 0
	dfs(tree, vis, 0, 0, &target, &ll)

	vis = make([]int, len(edges)+1)
	start, target, ll := target, 0, 0
	dfs(tree, vis, start, 0, &target, &ll)

	return ll
}
