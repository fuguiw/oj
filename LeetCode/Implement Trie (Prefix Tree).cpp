#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : child(26, nullptr), preFreq(0), wordFreq(0) { }

    vector<TrieNode *> child;
    int preFreq;
    int wordFreq;
    char NodeChar;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        if (s.size() == 0)
            return ;

        TrieNode *CurrNode = root;

        for (int i = 0; i < s.size(); i++) {
            int branch = s[i] - 'a';
            if (CurrNode->child[branch] == nullptr) {
                CurrNode->child[branch] = new TrieNode();
            }
            CurrNode = CurrNode->child[branch];
            CurrNode->NodeChar = s[i];
            CurrNode->preFreq++;
        }
        CurrNode->wordFreq++;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *CurrNode = root;
        for (int i = 0; i < key.size(); i++) {
            int branch = key[i] - 'a';
            if (CurrNode->child[branch] == nullptr)
                return false;
            CurrNode = CurrNode->child[branch];
        }

        if (CurrNode->wordFreq > 0)
            return true;

        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *CurrNode = root;

        for (int i = 0; i < prefix.size(); i++) {
            int branch = prefix[i] - 'a';
            if (CurrNode->child[branch] == nullptr)
                return false;
            CurrNode = CurrNode->child[branch];
        }

        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
//
int main(int argc, char *argv[])
{
    Trie trie;

    trie.insert("hello");
    trie.insert("he");
    trie.insert("and");
    trie.insert("mouse");
    trie.insert("kyne");

    cout << trie.search("mouse") << endl;
    cout << trie.search("andw") << endl;
    cout << trie.startsWith("hel") << endl;
    cout << trie.search("hel") << endl;

    return 0;
}

