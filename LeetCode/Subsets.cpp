#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());

        vector<vector<int>> vv;
        vector<int> v;

        vv.push_back(v);
        for (decltype(S.size()) i = 0; i < S.size(); i++) {
            vector<int>::size_type len = vv.size();
            for (decltype(S.size()) j = 0; j < len; j++) {
                v = vv[j];
                v.push_back(S[i]);
                vv.push_back(v);
            }
        }

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
