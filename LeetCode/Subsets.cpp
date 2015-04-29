#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void subset(vector<vector<int>> &vv, vector<int> &v, vector<int> &s, vector<int>::size_type i) {
        if (i == s.size()) {
            vv.push_back(v);
            return ;
        }

        subset(vv, v, s, i + 1);
        v.push_back(s[i]);
        subset(vv, v, s, i + 1);
        v.pop_back();
    }

public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());

        vector<vector<int>> vv;
        vector<int> v;
        subset(vv, v, S, 0);

        return vv;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v{4,1,0};
    vector<vector<int>> vv = sol.subsets(v);

    for (auto &n : vv) {
        for (auto i : n)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
