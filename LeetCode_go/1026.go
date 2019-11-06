package main

import (
	"fmt"
	"math"
)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func Max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func Min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func Abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func dfs(root *TreeNode, result *int) (min, max int) {
	min, max = math.MaxInt32, math.MinInt32

	if root.Left != nil {
		t1, t2 := dfs(root.Left, result)
		min = Min(min, t1)
		max = Min(min, t2)
	}
	if root.Right != nil {
		t1, t2 := dfs(root.Right, result)
		min = Min(min, t1)
		max = Min(min, t2)
	}

	if min != math.MaxInt32 {
		*result = Max(*result, Abs(root.Val-min))
	}
	if max != math.MinInt32 {
		*result = Max(*result, Abs(root.Val-max))
	}

	min = Min(min, root.Val)
	max = Max(max, root.Val)
	fmt.Println(root.Val, min, max)

	return
}

func maxAncestorDiff(root *TreeNode) int {
	result := 0
	if root != nil {
		dfs(root, &result)
	}
	return result
}
