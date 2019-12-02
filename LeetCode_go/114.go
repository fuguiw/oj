package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func find(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

	pre := root

	if root.Left != nil {
		pre = find(root.Left)
		pre.Right = root.Right
		root.Right = root.Left
		root.Left = nil
	}

	if pre.Right != nil {
		pre = find(pre.Right)
	}

	return pre
}

func flatten(root *TreeNode) {
	find(root)
}
