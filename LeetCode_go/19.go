package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	tail := head
	for i := 0; i < n; i++ {
		tail = tail.Next
	}
	if tail == nil {
		return head.Next
	}

	cur := head
	for tail.Next != nil {
		cur = cur.Next
		tail = tail.Next
	}

	cur.Next = cur.Next.Next
	return head
}
