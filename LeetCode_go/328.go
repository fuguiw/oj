package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
	if head == nil {
		return head
	}

	eHead := head.Next
	odd, even := head, eHead
	for odd != nil {
		if even == nil || even.Next == nil {
			odd.Next = eHead
			break
		}
		odd.Next = even.Next
		odd = odd.Next
		even.Next = odd.Next
		even = even.Next
	}

	return head
}
