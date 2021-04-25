package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func increasingBST(root *TreeNode) *TreeNode {
	var ans, pre *TreeNode = nil, nil

	var dfs func(r *TreeNode)
	dfs = func(r *TreeNode) {
		if r == nil {
			return
		}
		dfs(r.Left)
		next := r.Right
		if pre != nil {
			pre.Left = nil
		} else {
			ans = r
		}
		pre = r
		r.Left = nil
		dfs(next)
	}
	dfs(root)
	return ans
}
