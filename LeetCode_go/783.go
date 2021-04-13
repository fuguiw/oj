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

func min(x, y int) int {
	if x > y {
		return y
	}
	return x
}

func minDiffInBST(root *TreeNode) int {
	ans, pre := math.MaxInt32, math.MinInt32
	var find func(*TreeNode)
	find = func(r *TreeNode) {
		if r == nil {
			return
		}
		find(r.Left)
		ans = min(ans, r.Val-pre)
		pre = r.Val
		find(r.Right)
	}
	find(root)
	return ans
}
