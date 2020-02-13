package main

import "container/list"

type CQueue struct {
	st1 *list.List
	st2 *list.List
}

func Constructor() CQueue {
	cq := CQueue{}
	cq.st1 = list.New()
	cq.st2 = list.New()
	return cq
}

func (this *CQueue) AppendTail(value int) {
	this.st2.PushBack(value)
}

func (this *CQueue) DeleteHead() int {
	if this.st1.Len() == 0 {
		for this.st2.Len() != 0 {
			this.st1.PushBack(this.st2.Back().Value.(int))
			this.st2.Remove(this.st2.Back())
		}
	}

	if this.st1.Len() == 0 {
		return -1
	}
	h := this.st1.Back().Value.(int)
	this.st1.Remove(this.st1.Back())
	return h
}

/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */
