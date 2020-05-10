package main

import "math"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
	first := true
	pre := math.MinInt32
	var dfs func(root *TreeNode) bool
	dfs = func(root *TreeNode) bool {
		if root == nil {
			return true
		}

		if dfs(root.Left) == false {
			return false
		}
		if !first && root.Val <= pre {
			return false
		}
		pre = root.Val
		first = false
		if dfs(root.Right) == false {
			return false
		}

		return true
	}

	return dfs(root)
}
