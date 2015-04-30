#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void permute(vector<vector<int>> &vv, vector<int> num, vector<int>::size_type i) {
        if (i == num.size()) {
            vv.push_back(num);
            return ;
        }

        for (vector<int>::size_type j = i; j < num.size(); j++) {
            swap(num[i], num[j]);
            permute(vv, num, i + 1);
        }
    }

public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> vv;
        permute(vv, num, 0);
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
