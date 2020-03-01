package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	var pre *ListNode = nil
	for cur := head; cur != nil; {
		next := cur.Next
		cur.Next, pre = pre, cur
		cur = next
	}

	return pre
}
