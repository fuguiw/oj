package main

type node struct {
	exist bool
	word  bool
	trie  Trie
}

type Trie struct {
	trie []node
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	t := this
	for i := range word {
		if t.trie == nil {
			t.trie = make([]node, 26)
		}

		t.trie[word[i]-'a'].exist = true
		if i == len(word)-1 {
			t.trie[word[i]-'a'].word = true
		}
		t = &t.trie[word[i]-'a'].trie
	}
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	t := this
	for i := range word {
		if t.trie == nil {
			return false
		}
		if !t.trie[word[i]-'a'].exist {
			return false
		}
		if i == len(word)-1 && t.trie[word[i]-'a'].word {
			return true
		}
		t = &t.trie[word[i]-'a'].trie
	}
	return false
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	t := this
	for i := range prefix {
		if t.trie == nil {
			return false
		}
		if !t.trie[prefix[i]-'a'].exist {
			return false
		}
		t = &t.trie[prefix[i]-'a'].trie
	}
	return true
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
