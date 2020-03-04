package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func find(root *TreeNode, level int, nodes *[][]int) {
	if root == nil {
		return
	}
	if len(*nodes) <= level {
		*nodes = append(*nodes, []int{})
	}
	(*nodes)[level] = append((*nodes)[level], root.Val)
	find(root.Left, level+1, nodes)
	find(root.Right, level+1, nodes)
}

func levelOrder(root *TreeNode) []int {
	var nodes [][]int
	find(root, 0, &nodes)

	var ans []int
	for _, v := range nodes {
		for _, n := range v {
			ans = append(ans, n)
		}
	}
	return ans
}
