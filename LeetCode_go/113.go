package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pathSum(root *TreeNode, sum int) [][]int {
	var ans [][]int

	var dfs func(*TreeNode, int, int, []int)
	dfs = func(root *TreeNode, s int, l int, path []int) {
		if root == nil {
			return
		}

		if len(path) > l {
			path[l+1] = root.Val
		} else {
			path = append(path, root.Val)
		}
		s += root.Val

		if root.Left == nil && root.Right == nil && s == sum {
			t := make([]int, len(path))
			copy(t, path)
			ans = append(ans, t)
		}

		dfs(root.Left, s, l+1, path)
		dfs(root.Right, s, l+1, path)
	}

	dfs(root, 0, 0, []int{})

	return ans
}
