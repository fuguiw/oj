package main

import "container/list"

type MyQueue struct {
	st1 *list.List
	st2 *list.List
}

/** Initialize your data structure here. */
func Constructor() MyQueue {
	q := MyQueue{}
	q.st1 = list.New()
	q.st2 = list.New()
	return q
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int) {
	this.st2.PushBack(x)
}

/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
	v := this.Peek()
	this.st1.Remove(this.st1.Back())
	return v

}

/** Get the front element. */
func (this *MyQueue) Peek() int {
	if this.st1.Len() == 0 {
		for this.st2.Len() != 0 {
			this.st1.PushBack(this.st2.Back().Value.(int))
			this.st2.Remove(this.st2.Back())
		}
	}

	v := this.st1.Back().Value.(int)
	return v
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
	return this.st1.Len() == 0 && this.st2.Len() == 0
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
