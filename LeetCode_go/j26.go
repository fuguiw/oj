package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isSub(a, b *TreeNode) bool {
	if b == nil {
		return true
	}

	if a == nil || a.Val != b.Val {
		return false
	}

	if isSub(a.Left, b.Left) && isSub(a.Right, b.Right) {
		return true
	}
	return false
}

func isSubStructure(A *TreeNode, B *TreeNode) bool {
	if B == nil || A == nil {
		return false
	}

	if isSub(A, B) || isSubStructure(A.Left, B) || isSubStructure(A.Right, B) {
		return true
	}

	return false
}
