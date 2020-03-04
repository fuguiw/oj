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
	if level%2 == 1 {
		(*nodes)[level] = append([]int{root.Val}, (*nodes)[level]...)
	} else {
		(*nodes)[level] = append((*nodes)[level], root.Val)
	}
	find(root.Left, level+1, nodes)
	find(root.Right, level+1, nodes)
}

func levelOrder(root *TreeNode) [][]int {
	var nodes [][]int
	find(root, 0, &nodes)

	return nodes
}
