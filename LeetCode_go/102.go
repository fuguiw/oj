package main

import "container/list"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrder(root *TreeNode) [][]int {
	var result [][]int

	if root == nil {
		return result
	}

	q := list.New()
	q.PushBack(root)

	for q.Len() != 0 {
		var l []int
		tq := list.New()
		for q.Len() != 0 {
			node := q.Front().Value.(*TreeNode)
			l = append(l, node.Val)
			if node.Left != nil {
				tq.PushBack(node.Left)
			}
			if node.Right != nil {
				tq.PushBack(node.Right)
			}
			q.Remove(q.Front())
		}
		result = append(result, l)
		q = tq
	}
	return result
}
