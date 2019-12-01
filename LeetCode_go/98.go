package main

import "fmt"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func find(root *TreeNode, first *bool, pre *int, ans *bool) {
	if root == nil {
		return
	}

	find(root.Left, first, pre, ans)

	if *first {
		*first = false
	} else {
		if root.Val <= *pre {
			*ans = false
			return
		}
	}
	*pre = root.Val

	find(root.Right, first, pre, ans)
}

func isValidBST(root *TreeNode) bool {
	first, ans := true, true
	var pre int
	find(root, &first, &pre, &ans)
	return ans
}
