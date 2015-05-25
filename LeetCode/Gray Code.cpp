#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    void garyCode(vector<int> &v, unordered_set<int> &s, int n) {
        int code, i, tmp;

        for (; ; ) {
            code = v.back();

            for (i = 0; i < n; i++) {
                tmp = code ^ (1 << i);
                if (s.find(tmp) == s.end())
                    break;
            }

            if (i == n)
                break;

            s.insert(tmp);
            v.push_back(tmp);
        }
    }

public:
    vector<int> grayCode(int n) {
        vector<int> v(1, 0);
        unordered_set<int> s;
        s.insert(0);
        garyCode(v, s, n);
        return v;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v = sol.grayCode(4);
    for (auto i : v)
        cout << i << endl;
    return 0;
}
