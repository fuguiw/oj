package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func find(root *TreeNode, k int, n, ans *int) {
	if root == nil {
		return
	}

	find(root.Right, k, n, ans)
	*n++
	if *n == k {
		*ans = root.Val
		return
	}
	find(root.Left, k, n, ans)
}

func kthLargest(root *TreeNode, k int) int {
	n, ans := 0, 0
	find(root, k, &n, &ans)
	return ans
}
