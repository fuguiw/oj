package main

import "container/list"

type MyHashMap struct {
	data []list.List
}

type pair struct {
	key   int
	value int
}

const mod = 857

/** Initialize your data structure here. */
func Constructor() MyHashMap {
	hashMap := MyHashMap{}
	hashMap.data = make([]list.List, mod)
	return hashMap
}

/** value will always be non-negative. */
func (this *MyHashMap) Put(key int, value int) {
	k := key % mod
	for p := this.data[k].Front(); p != nil; p = p.Next() {
		if p.Value.(pair).key == key {
			p.Value = pair{key, value}
			return
		}
	}
	this.data[k].PushBack(pair{key, value})
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
func (this *MyHashMap) Get(key int) int {
	k := key % mod
	for p := this.data[k].Front(); p != nil; p = p.Next() {
		if p.Value.(pair).key == key {
			return p.Value.(pair).value
		}
	}
	return -1
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
func (this *MyHashMap) Remove(key int) {
	k := key % mod
	for p := this.data[k].Front(); p != nil; p = p.Next() {
		if p.Value.(pair).key == key {
			this.data[k].Remove(p)
		}
	}
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */
