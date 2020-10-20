package main

import "sort"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func convert(root *TreeNode) []int {
	var ans []int
	var find func(*TreeNode)
	find = func(r *TreeNode) {
		if r == nil {
			return
		}
		ans = append(ans, r.Val)
		find(r.Left)
		find(r.Right)
	}
	find(root)
	return ans
}

func getAllElements(root1 *TreeNode, root2 *TreeNode) []int {
	ans := convert(root1)
	ans = append(ans, convert(root2)...)
	sort.Ints(ans)
	return ans
}
