package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func find(root *TreeNode, level int, ans *[][]int) {
	if root == nil {
		return
	}
	if level >= len(*ans) {
		*ans = append(*ans, []int{})
	}
	(*ans)[level] = append((*ans)[level], root.Val)

	find(root.Left, level+1, ans)
	find(root.Right, level+1, ans)
}

func levelOrder(root *TreeNode) [][]int {
	var ans [][]int
	find(root, 0, &ans)
	return ans
}
