package LeetCode_go

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
	if t1 == nil && t2 == nil {
		return nil
	}

	var root, l1, l2, r1, r2 *TreeNode

	if t1 != nil {
		root = t1
		l1 = t1.Left
		r1 = t1.Right
	}

	if t2 != nil {
		if root == nil {
			root = t2
		} else {
			root.Val += t2.Val
		}
		l2 = t2.Left
		r2 = t2.Right
	}

	root.Left = mergeTrees(l1, l2)
	root.Right = mergeTrees(r1, r2)

	return root
}
