#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> l, r;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                l.push_back(i);
            } else if (s[i] == ')') {
                if (l.empty()) {
                    r.push_back(i);
                } else {
                    l.pop_back();
                }
            }
        }

        string ans;
        for (int i = 0, li = 0, ri = 0; i < s.size(); i++) {
            if (li < l.size() && l[li] == i) {
                li++;
                continue;
            }
            if (ri < r.size() && r[ri] == i) {
                ri++;
                continue;
            }
            ans += s[i];
        }

        return ans;
    }
};
