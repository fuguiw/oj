package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func doRob(root *TreeNode) (amount1 int, amount2 int) {
	amount1 = 0
	amount2 = 0

	if root == nil {
		return
	}

	leftAmount1 := 0
	leftAmount2 := 0
	if root.Left != nil {
		leftAmount1, leftAmount2 = doRob(root.Left)
	}

	rightAmount1 := 0
	rightAmount2 := 0
	if root.Right != nil {
		rightAmount1, rightAmount2 = doRob(root.Right)
	}

	amount1 = root.Val + leftAmount2 + rightAmount2
	if leftAmount1 > leftAmount2 {
		amount2 += leftAmount1
	} else {
		amount2 += leftAmount2
	}

	if rightAmount1 > rightAmount2 {
		amount2 += rightAmount1
	} else {
		amount2 += rightAmount2
	}

	return
}

func rob(root *TreeNode) int {
	amount1, amount2 := doRob(root)
	if amount1 > amount2 {
		return amount1
	} else {
		return amount2
	}
}
