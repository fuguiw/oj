package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteNode(head *ListNode, val int) *ListNode {
	if head.Val == val {
		return head.Next
	}
	for cur := head; cur.Next != nil; cur = cur.Next {
		if cur.Next.Val == val {
			cur.Next = cur.Next.Next
			break
		}
	}
	return head
}
