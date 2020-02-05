package main

import (
	"container/heap"
	"fmt"
	"sort"
)

// An Item is something we manage in a priority queue.
type Item struct {
	value    int // The value of the item; arbitrary.
	priority int // The priority of the item in the queue.
	// The index is needed by update and is maintained by the heap.Interface methods.
	index int // The index of the item in the heap.
}

// A PriorityQueue implements heap.Interface and holds Items.
type PriorityQueue []*Item

func (pq *PriorityQueue) Len() int { return len(*pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	// We want Pop to give us the highest, not lowest, priority so we use greater than here.
	return pq[i].priority < pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) { //用指针，因为要修改成员
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	item.index = -1 // for safety
	*pq = old[0 : n-1]
	return item
}

func minMeetingRooms(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	pq := make(PriorityQueue, 0)
	for i, interval := range intervals {
		if len(pq) == 0 {
			heap.Push(&pq, &Item{interval[1], interval[1], i})
			continue
		}
		item := heap.Pop(&pq).(*Item)
		if item.value <= interval[0] {
			item.value, item.priority = interval[1], interval[1]
			heap.Push(&pq, item)
		} else {
			heap.Push(&pq, item)
			heap.Push(&pq, &Item{interval[1], interval[1], i})
		}
	}

	fmt.Println(([]*Item(pq)))
	return len(pq)
}
