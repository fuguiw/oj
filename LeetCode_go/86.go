package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
	l1, l2 := &ListNode{}, &ListNode{}
	h1, h2 := l1, l2

	for ; head != nil; head = head.Next {
		if head.Val < x {
			l1.Next = head
			l1 = l1.Next
		} else {
			l2.Next = head
			l2 = l2.Next
		}
	}
	l1.Next = h2.Next
	l2.Next = nil
	return h1.Next
}
