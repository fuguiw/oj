package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func find(root *TreeNode, result *int, level int, maxLevel *int) {
	if level > *maxLevel {
		*result = root.Val
		*maxLevel = level
	}

	if root.Left != nil {
		find(root.Left, result, level+1, maxLevel)
	}
	if root.Right != nil {
		find(root.Right, result, level+1, maxLevel)
	}
}

func findBottomLeftValue(root *TreeNode) int {
	result := root.Val
	level, maxLevel := 0, 0
	find(root, &result, level, &maxLevel)
	return result
}
