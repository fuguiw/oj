#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        unordered_map<string, int> m;
        vector<string> v;

        int len = strs.size();
        for (int i = 0; i < len; i++) {
            string &str = strs[i];
            string tmp(str);
            sort(tmp.begin(), tmp.end());
            if (m.find(tmp) != m.end()) {
                v.push_back(str);
                if (m[tmp] != -1) {
                    v.push_back(strs[m[tmp]]);
                    m[tmp] = -1;
                }
            } else {
                m[tmp] = i;
            }
        }

        return v;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<string> vs{"and", "dan"};
    vector<string> v = sol.anagrams(vs);
    for (auto s : v)
        cout << s << endl;
    return 0;
}
