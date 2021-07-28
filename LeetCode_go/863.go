package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func distanceK(root *TreeNode, target *TreeNode, k int) []int {
	parents := make(map[int]*TreeNode)
	var findParent func(node *TreeNode)
	findParent = func(node *TreeNode) {
		if node.Left != nil {
			parents[node.Left.Val] = node
			findParent(node.Left)
		}
		if node.Right != nil {
			parents[node.Right.Val] = node
			findParent(node.Right)
		}
	}
	findParent(root)

	var ans []int
	var find func(*TreeNode, *TreeNode, int)
	find = func(node, from *TreeNode, step int) {
		if node == nil {
			return
		}
		if step == k {
			ans = append(ans, node.Val)
			return
		}
		if node.Left != from {
			find(node.Left, node, step+1)
		}
		if node.Right != from {
			find(node.Right, node, step+1)
		}
		if parents[node.Val] != from {
			find(parents[node.Val], node, step+1)
		}
	}
	find(target, nil, 0)

	return ans
}
