package main

import "container/list"

type MyHashSet struct {
	data []*list.List
}

const mod int = 1111

/** Initialize your data structure here. */
func Constructor() MyHashSet {
	hashSet := MyHashSet{}
	hashSet.data = make([]*list.List, mod)
	for i := range hashSet.data {
		hashSet.data[i] = list.New()
	}
	return hashSet
}

func (this *MyHashSet) Add(key int) {
	if !this.Contains(key) {
		k := key % mod
		this.data[k].PushBack(key)
	}
}

func (this *MyHashSet) Remove(key int) {
	k := key % mod
	for e := this.data[k].Front(); e != nil; e = e.Next() {
		if key == e.Value.(int) {
			this.data[k].Remove(e)
		}
	}
}

/** Returns true if this set contains the specified element */
func (this *MyHashSet) Contains(key int) bool {
	k := key % mod
	for e := this.data[k].Front(); e != nil; e = e.Next() {
		if key == e.Value.(int) {
			return true
		}
	}
	return false
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(key);
 * obj.Remove(key);
 * param_3 := obj.Contains(key);
 */
