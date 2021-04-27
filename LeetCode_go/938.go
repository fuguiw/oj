package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rangeSumBST(root *TreeNode, low int, high int) int {
	ans := 0

	var dfs func(r *TreeNode)
	dfs = func(r *TreeNode) {
		if r == nil {
			return
		}
		dfs(r.Left)
		if r.Val > high {
			return
		}
		if r.Val >= low {
			ans += r.Val
		}
		dfs(r.Right)
	}
	dfs(root)
	return ans
}
