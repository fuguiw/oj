package main

/**
 * Definition for a Node.
 */
type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

func copyRandomList(head *Node) *Node {
	if head == nil {
		return nil
	}

	for cur := head; cur != nil; {
		n := &Node{Val: cur.Val}
		n.Next = cur.Next
		n.Random = cur.Random
		cur.Next = n
		cur = cur.Next.Next
	}

	for cur := head.Next; cur != nil; {
		if cur.Random != nil {
			cur.Random = cur.Random.Next
		}
		cur = cur.Next
		if cur != nil {
			cur = cur.Next
		}
	}

	ret := head.Next

	for cur, n := head, head.Next; cur != nil; {
		cur.Next = n.Next
		cur = cur.Next
		if cur != nil {
			n.Next = cur.Next
		}
		n = n.Next
	}

	return ret
}
