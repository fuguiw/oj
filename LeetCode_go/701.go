package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func insertIntoBST(root *TreeNode, val int) *TreeNode {
	node := &TreeNode{
		Val: val,
	}

	if root == nil {
		return node
	}

	for pre := root; pre != nil; {
		if pre.Val > val {
			if pre.Left == nil {
				pre.Left = node
				return root
			}
			pre = pre.Left
		} else {
			if pre.Right == nil {
				pre.Right = node
				return root
			}
			pre = pre.Right
		}
	}
	return root
}
