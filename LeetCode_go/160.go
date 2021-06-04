package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	m, n := 1, 1
	var nodeA, nodeB *ListNode
	for nodeA := headA; nodeA.Next != nil; nodeA = nodeA.Next {
		m++
	}
	for nodeB := headB; nodeB.Next != nil; nodeB = nodeB.Next {
		n++
	}
	if nodeA != nodeB {
		return nil
	}

	nodeA = headA
	for i := 0; i < m-n; i++ {
		nodeA = nodeA.Next
	}
	nodeB = headB
	for i := 0; i < n-m; i++ {
		nodeB = nodeB.Next
	}
	for ; nodeA != nil; nodeA, nodeB = nodeA.Next, nodeB.Next {
		if nodeA == nodeB {
			return nodeA
		}
	}
	return nodeA
}
