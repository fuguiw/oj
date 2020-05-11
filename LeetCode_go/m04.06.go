package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderSuccessor(root *TreeNode, p *TreeNode) *TreeNode {
	find := false
	var dfs func(*TreeNode) *TreeNode
	dfs = func(root *TreeNode) *TreeNode {
		if root == nil {
			return nil
		}
		if ans := dfs(root.Left); ans != nil {
			return ans
		}
		if find {
			return root
		}
		if root == p {
			find = true
		}
		if ans := dfs(root.Right); ans != nil {
			return ans
		}
		return nil
	}

	return dfs(root)
}
