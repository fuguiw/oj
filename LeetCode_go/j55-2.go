package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func find(root *TreeNode, level int, dep *int) {
	if root == nil {
		return
	}
	if level > *dep {
		*dep = level
	}
	find(root.Left, level+1, dep)
	find(root.Right, level+1, dep)
}

func maxDepth(root *TreeNode) int {
	ans := 0
	find(root, 1, &ans)
	return ans
}
