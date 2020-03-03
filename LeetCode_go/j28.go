package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func find(left, right *TreeNode) bool {
	if left == nil && right == nil {
		return true
	}
	if left == nil || right == nil || left.Val != right.Val {
		return false
	}

	return find(left.Left, right.Right) && find(left.Right, right.Left)
}

func isSymmetric(root *TreeNode) bool {
	return root == nil || find(root.Left, root.Right)
}
