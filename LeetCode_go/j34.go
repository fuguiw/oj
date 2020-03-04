package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func find(root *TreeNode, sum int, target int, path []int, ans *[][]int) {
	if root == nil {
		return
	}

	sum += root.Val
	path = append(path, root.Val)
	if root.Left == nil && root.Right == nil && target == sum {
		p := make([]int, len(path))
		copy(p, path)
		*ans = append(*ans, p)
		return
	}

	find(root.Left, sum, target, path, ans)
	find(root.Right, sum, target, path, ans)
}

func pathSum(root *TreeNode, sum int) [][]int {
	var ans [][]int
	find(root, 0, sum, []int{}, &ans)
	return ans
}
