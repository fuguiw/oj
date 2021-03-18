package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {
	h := &ListNode{
		Next: head,
	}

	pre := h
	for i := 0; i < m-1; i++ {
		pre = pre.Next
	}
	cur := pre.Next
	for i := 0; i < n-m; i++ {
		next := cur.Next
		cur.Next = next.Next
		next.Next = pre.Next
		pre.Next = next
	}

	return h.Next
}
