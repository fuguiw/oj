package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
	if t1 == nil && t2 == nil {
		return nil
	}
	var l1, l2, r1, r2, root *TreeNode
	if t1 != nil {
		l1 = t1.Left
		r1 = t1.Right
		root = t1
	}
	if t2 != nil {
		l2 = t2.Left
		r2 = t2.Right
		if root == nil {
			root = t2
		} else {
			root.Val += t2.Val
		}
	}

	root.Left = mergeTrees(l1, l2)
	root.Right = mergeTrees(r1, r2)

	return root
}
