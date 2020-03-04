package main

func verifyPostorder(postorder []int) bool {
	if len(postorder) == 0 {
		return true
	}
	root := postorder[len(postorder)-1]
	idx := 0
	for ; idx < len(postorder)-1; idx++ {
		if postorder[idx] > root {
			break
		}
	}
	if verifyPostorder(postorder[0:idx]) == false {
		return false
	}

	for i := idx; i < len(postorder)-1; i++ {
		if postorder[i] < root {
			return false
		}
	}
	return verifyPostorder(postorder[idx : len(postorder)-1])
}
