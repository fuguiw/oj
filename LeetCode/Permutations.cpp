#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> vv;
        vector<int> v;
        auto len = num.size();
        vv.push_back(v);

        for (vector<int>::size_type i = 0; i < len; i++) {
            for (v = vv.front(); v.size() <= i; v = vv.front()) {
                for (vector<int>::size_type j = 0; j < v.size(); j++) {
                    vector<int> tmp(v);

                    tmp.insert(tmp.begin() + j, num[i]);
                    vv.push_back(tmp);
                }

                v.insert(v.end(), num[i]);
                vv.push_back(v);
                vv.erase(vv.begin());
            }
        }

        return vv;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v;
    vector<vector<int> > vv;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vv = sol.permute(v);

    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[0].size(); j++)
            cout << vv[i][j];
        cout << endl;
    }

    return 0;
}
