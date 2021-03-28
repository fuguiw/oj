package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type BSTIterator struct {
	nums []int
	idx  int
}

func Constructor(root *TreeNode) BSTIterator {
	bst := BSTIterator{idx: -1}
	var construct func(node *TreeNode)
	construct = func(node *TreeNode) {
		if node == nil {
			return
		}
		construct(node.Left)
		bst.nums = append(bst.nums, node.Val)
		construct(node.Right)
	}
	construct(root)
	return bst
}

/** @return the next smallest number */
func (this *BSTIterator) Next() int {
	this.idx++
	return this.nums[this.idx]
}

/** @return whether we have a next smallest number */
func (this *BSTIterator) HasNext() bool {
	return this.idx < len(this.nums)-1
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
