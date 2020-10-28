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

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxPathSum(root *TreeNode) int {
	ans := math.MinInt32
	var find func(*TreeNode) int
	find = func(r *TreeNode) int {
		if r == nil {
			return 0
		}

		left := max(0, find(r.Left))
		right := max(0, find(r.Right))

		ans = max(ans, r.Val+left+right)
		return r.Val + max(left, right)
	}
	find(root)
	return ans
}
