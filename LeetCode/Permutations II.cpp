#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void permuteUnique(vector<int> v, vector<vector<int>> &vv, vector<int>::size_type i) {
        if (i == v.size()) {
            vv.push_back(v);
            return ;
        }

        for (vector<int>::size_type j = i; j < v.size(); j++) {
            if (j > i && v[j] == v[i])
                continue;
            swap(v[i], v[j]);
            permuteUnique(v, vv, i + 1);
        }
    }

public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> vv;
        vector<int> v(num);

        sort(v.begin(), v.end());
        permuteUnique(v, vv, 0);

        return vv;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v;
    vector<vector<int> > vv;

    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(9);
    
    vv = sol.permuteUnique(v);
    cout << vv.size() << endl;

    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[0].size(); j++)
            cout << vv[i][j];
        cout << endl;
    }

    return 0;
}
