package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getKthFromEnd(head *ListNode, k int) *ListNode {
	cur := head
	for k > 0 {
		k--
		cur = cur.Next
	}

	for cur != nil {
		head, cur = head.Next, cur.Next
	}

	return head
}
