package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func lowestCommonAncestor(root *TreeNode, p *TreeNode, q *TreeNode) *TreeNode {
	ans := root
	var dfs func(*TreeNode) bool
	dfs = func(root *TreeNode) bool {
		if root == nil {
			return false
		}

		if root.Val == p.Val || root.Val == q.Val {
			if dfs(root.Left) || dfs(root.Right) {
				ans = root
			}
			return true
		}
		l, r := dfs(root.Left), dfs(root.Right)
		if l && r {
			ans = root
		}
		return l || r
	}

	dfs(root)
	return ans
}
