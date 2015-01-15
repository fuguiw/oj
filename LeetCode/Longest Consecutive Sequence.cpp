#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        set<int> s(num.begin(), num.end());
        set<int>::iterator it;
        int pre;
        int len = 0;
        int ret = 0;

        for (it = s.begin(); it != s.end(); it++) {
            if (it == s.begin()) {
                len = ret = 1;
                pre = *it;
                continue;
            }

            if (*it == pre + 1) {
                ++len;
            } else {
                ret = max(ret, len);
                len = 1;
            }

            pre = *it;
        }

        ret = max(ret, len);

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v;

    v.push_back(100);
    v.push_back(4);
    v.push_back(200);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);
    
    cout << sol.longestConsecutive(v) << endl;

    return 0;
}
