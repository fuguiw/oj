#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
    TrieNode() : children(26, nullptr), word() {}
    vector<TrieNode *> children;
    bool word;
};

class WordDictionary {
public:
    WordDictionary() : trie(new TrieNode) {}

    // Adds a word into the data structure.
    void addWord(string word) {
        if (word.empty())
            return ;

        TrieNode *curr = trie;

        for (int i = 0; i < word.size(); i++) {
            int branch = word[i] - 'a';
            if (curr->children[branch] == nullptr)
                curr->children[branch] = new TrieNode;
            curr = curr->children[branch];
        }

        curr->word = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(trie, word, 0);
    }

private:
    bool search(TrieNode *curr, string &word, int i) {
        if (i != 0 && i == word.size())
            return curr->word;

        bool rnt = false;
        if (word[i] == '.') {
            for (auto node : curr->children) {
                if (node != nullptr)
                    rnt |= search(node, word, i + 1);
            }
        } else {
            int branch = word[i] - 'a';
            if (curr->children[branch] != nullptr)
                return search(curr->children[branch], word, i + 1);
        }

        return rnt;
    }

    TrieNode *trie;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main(int argc, char *argv[])
{
    WordDictionary d;
    d.addWord("word");

    cout << d.search("word") << endl;
    cout << d.search("wo.") << endl;

    return 0;
}
