package main

import "reflect"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	var dfs func(root *TreeNode, leaves *[]int)
	dfs = func(root *TreeNode, leaves *[]int) {
		if root == nil {
			return
		}
		dfs(root.Left, leaves)
		if root.Left == nil && root.Right == nil {
			*leaves = append(*leaves, root.Val)
		}
		dfs(root.Right, leaves)
	}

	var leaves1 []int
	var leaves2 []int
	dfs(root1, &leaves1)
	dfs(root2, &leaves2)

	return reflect.DeepEqual(leaves1, leaves2)
}
