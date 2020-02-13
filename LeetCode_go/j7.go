package main

import "fmt"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func buildTree(preorder []int, inorder []int) *TreeNode {
	//fmt.Println(preorder)
	//fmt.Println(inorder)
	if len(preorder) == 0 {
		return nil
	}

	root := &TreeNode{Val: preorder[0]}
	i := 0
	for i = 0; i < len(inorder); i++ {
		if preorder[0] == inorder[i] {
			break
		}
	}

	root.Left = buildTree(preorder[1:1+i], inorder[0:i])
	root.Right = buildTree(preorder[1+i:], inorder[i+1:])

	return root
}
