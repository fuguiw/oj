package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
	if k == 0 || head == nil || head.Next == nil {
		return head
	}

	n := 1
	node := head
	for ; node.Next != nil; node = node.Next {
		n++
	}
	add := n - k%n
	if add == n {
		return head
	}

	node.Next = head
	for ; add > 0; add-- {
		node = node.Next
	}

	ans := node.Next
	node.Next = nil
	return ans
}
