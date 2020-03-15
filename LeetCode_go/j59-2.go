package main

import "container/list"

type MaxQueue struct {
	max   *list.List
	queue *list.List
}

func Constructor() MaxQueue {
	return MaxQueue{
		max:   list.New(),
		queue: list.New(),
	}
}

func (this *MaxQueue) Max_value() int {
	if this.max.Len() == 0 {
		return -1
	}
	return this.max.Front().Value.(int)
}

func (this *MaxQueue) Push_back(value int) {
	this.queue.PushBack(value)
	for this.max.Len() != 0 {
		if this.max.Back().Value.(int) >= value {
			break
		}
		this.max.Remove(this.max.Back())
	}
	this.max.PushBack(value)
}

func (this *MaxQueue) Pop_front() int {
	if this.queue.Len() == 0 {
		return -1
	}
	front := this.queue.Front().Value.(int)
	if front == this.max.Front().Value.(int) {
		this.max.Remove(this.max.Front())
	}
	this.queue.Remove(this.queue.Front())
	return front
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Max_value();
 * obj.Push_back(value);
 * param_3 := obj.Pop_front();
 */
