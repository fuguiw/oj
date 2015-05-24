#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void combinationSum3(vector<vector<int>> &vv, vector<int> &v, int k, int n, int curr, int val, int sum) {
        if (n / (k - curr)  < val)
            return ;

        if (curr == k - 1) {
            v[curr] = n - sum;
            if (v[curr] > 9)
                return ;
            vv.push_back(v);
            return ;
        }

        int left = (n - sum);
        for (int i = val + 1; i <= left / (k - curr); i++) {
            if (left - i == i)
                return ;
            v[curr] = i; 
            combinationSum3(vv, v, k, n, curr + 1, i, sum + i);
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> vv;
        vector<int> v(k);
        combinationSum3(vv, v, k, n, 0, 0, 0);
        return vv;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<int>> vv = sol.combinationSum3(2, 18);
    for (auto &v : vv) {
        for (auto i : v)
            cout << i;
        cout << endl;
    }
    return 0;
}
