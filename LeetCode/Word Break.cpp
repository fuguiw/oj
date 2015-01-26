#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.size();
        vector<bool> v(s.size() + 1, false);

        v[0] = true;
        for (int i = 0; i <= len; i++) {
            if (v[i] == 0) continue;
            for (int j = i + 1; j <= len; j++) {
                if (dict.find(s.substr(i, j - i)) != dict.end())
                    v[j] = 1;
            }
        }

        return v[len];
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    unordered_set<string> dict;
    string s1("hello");
    string s2("word");
    string s3("helloworl");
    
    dict.insert(s1);
    dict.insert(s2);

    cout << sol.wordBreak(s3, dict) << endl;

    return 0;
}
