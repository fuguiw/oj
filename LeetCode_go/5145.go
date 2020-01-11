package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func find(root *TreeNode, ans *int, pv int) {
	if root == nil {
		return
	}

	if root.Left != nil && pv%2 == 0 {
		*ans += root.Left.Val
	}
	if root.Right != nil && pv%2 == 0 {
		*ans += root.Right.Val
	}
	find(root.Left, ans, root.Val)
	find(root.Right, ans, root.Val)
}

func sumEvenGrandparent(root *TreeNode) int {
	ans := 0
	if root != nil {
		find(root.Left, &ans, root.Val)
		find(root.Right, &ans, root.Val)
	}
	return ans
}
