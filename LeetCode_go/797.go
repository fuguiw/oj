package LeetCode_go

func findPath(graph [][]int, path []int, curNode int, result *[][]int) {
	if curNode == len(graph) - 1 {
		tmp := make([]int, len(path))
		copy(tmp, path)
		*result = append(*result, tmp)
	}

	for i := 0; i < len(graph[curNode]); i++ {
		findPath(graph, append(path, graph[curNode][i]), graph[curNode][i], result)
	}
}

func allPathsSourceTarget(graph [][]int) [][]int {
	var result [][]int
	path := []int{0}
	findPath(graph, path, 0, &result)
	return result
}
