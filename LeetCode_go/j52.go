package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	lenA := 0
	for h := headA; h != nil; h = h.Next {
		lenA++
	}
	lenB := 0
	for h := headB; h != nil; h = h.Next {
		lenB++
	}
	if lenA > lenB {
		for i := 0; i < lenA-lenB; i++ {
			headA = headA.Next
		}
	}
	if lenB > lenA {
		for i := 0; i < lenB-lenA; i++ {
			headB = headB.Next
		}
	}

	for ; headA != nil && headB != nil; headA, headB = headA.Next, headB.Next {
		if headA == headB {
			return headA
		}
	}
	return nil
}
