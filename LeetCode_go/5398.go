package main

import (
	"container/list"
	"fmt"
)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func goodNodes(root *TreeNode) int {
	st := list.New()
	ans := 0
	var dfs func(root *TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}

		if st.Len() == 0 || st.Front().Value.(int) <= root.Val {
			st.PushFront(root.Val)
			fmt.Println(root.Val, st.Front().Value.(int))
			ans++
		}
		dfs(root.Left)
		dfs(root.Right)
		if st.Front().Value.(int) == root.Val {
			st.Remove(st.Front())
		}
	}
	dfs(root)

	return ans
}
