package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func generate(start int, end int) []*TreeNode {
	if start > end {
		return []*TreeNode{nil}
	}

	var ans []*TreeNode
	for i := start; i <= end; i++ {
		left := generate(start, i-1)
		right := generate(i+1, end)

		for _, l := range left {
			for _, r := range right {
				root := &TreeNode{
					Val:   i,
					Left:  l,
					Right: r,
				}
				ans = append(ans, root)
			}
		}
	}

	return ans
}

func generateTrees(n int) []*TreeNode {
	if n == 0 {
		return []*TreeNode{}
	}
	return generate(1, n)
}
