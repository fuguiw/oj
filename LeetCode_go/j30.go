package main

import "container/list"

type MinStack struct {
	stack *list.List
	min   *list.List
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{
		stack: list.New(),
		min:   list.New(),
	}
}

func (this *MinStack) Push(x int) {
	this.stack.PushBack(x)
	if this.min.Len() == 0 || x <= this.min.Back().Value.(int) {
		this.min.PushBack(x)
	}
}

func (this *MinStack) Pop() {
	if this.stack.Back().Value.(int) == this.min.Back().Value.(int) {
		this.min.Remove(this.min.Back())
	}
	this.stack.Remove(this.stack.Back())
}

func (this *MinStack) Top() int {
	return this.stack.Back().Value.(int)
}

func (this *MinStack) Min() int {
	return this.min.Back().Value.(int)
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Min();
 */
