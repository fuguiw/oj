package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	d := make(map[int]int)
	for cur := head; cur != nil; cur = cur.Next {
		if cur.Next != nil && cur.Val == cur.Next.Val {
			d[cur.Val] = 1
		}
	}

	head = &ListNode{
		Next: head,
	}
	for cur := head; cur.Next != nil; {
		if _, ok := d[cur.Next.Val]; ok {
			cur.Next = cur.Next.Next
		} else {
			cur = cur.Next
		}
	}

	return head.Next
}
