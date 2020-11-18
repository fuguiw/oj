package main

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

func findFrequentTreeSum(root *TreeNode) []int {
	m := make(map[int]int)
	maxCount := 0
	var find func(root *TreeNode) int
	find = func(r *TreeNode) int {
		if r == nil {
			return 0
		}
		sum := find(r.Left) + find(r.Right) + r.Val
		m[sum]++
		maxCount = max(maxCount, m[sum])
		return sum
	}
	find(root)

	var ans []int
	for k, v := range m {
		if v == maxCount {
			ans = append(ans, k)
		}
	}

	return ans
}
