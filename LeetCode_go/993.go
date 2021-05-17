package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isCousins(root *TreeNode, x int, y int) bool {
	var find func(*TreeNode, int, int, *int, *int)
	find = func(r *TreeNode, target int, l int, p *int, level *int) {
		if r == nil {
			return
		}
		if (r.Left != nil && r.Left.Val == target) || (r.Right != nil && r.Right.Val == target) {
			*p = r.Val
			*level = l + 1
			return
		}
		find(r.Left, target, l+1, p, level)
		find(r.Right, target, l+1, p, level)
		return
	}

	var p1, l1, p2, l2 int
	find(root, x, 0, &p1, &l1)
	find(root, y, 0, &p2, &l2)
	return (l1 == l2) && (p1 != p2)
}
