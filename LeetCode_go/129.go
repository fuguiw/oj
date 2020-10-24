package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumNumbers(root *TreeNode) int {
	ans := 0

	var dfs func(*TreeNode, int)
	dfs = func(r *TreeNode, prev int) {
		if r == nil {
			return
		}

		prev = prev*10 + r.Val
		if r.Left == nil && r.Right == nil {
			ans += prev
		}

		dfs(r.Left, prev)
		dfs(r.Right, prev)
	}
	dfs(root, 0)

	return ans
}
