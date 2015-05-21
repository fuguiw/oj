#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    bool check(const string &word1, const string &word2) {
        int cnt = 0;
        int len = word1.size();
        for (int i = 0; i < len; i++) {
            if (word1[i] != word2[i])
                cnt++;
            if (cnt > 1)
                return false;
        }

        return cnt == 1;
    }

public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_map<string, int> steps;
        queue<string> q;
        q.push(beginWord);
        steps[beginWord] = 1;
        wordDict.insert(endWord);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            for (auto it = wordDict.begin(); it != wordDict.end(); ) {
                if (check(cur, *it)) {
                    steps[*it] = steps[cur] + 1;
                    if (*it == endWord)
                        return steps[*it];
                    q.push(*it);
                    it = wordDict.erase(it);
                } else {
                    ++it;
                }
            }
        }

        return 0;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    unordered_set<string> s{"hot", "dot", "dog", "lot", "log"};
    cout << sol.ladderLength("hit", "cog", s) << endl;
    return 0;
}
