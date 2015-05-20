#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void combinationSum2(vector<int> &candidates, int target, vector<vector<int>> &vv, vector<int> v, int i) {
        int len = candidates.size();
        int end = -1;
        for (; i < len; i++) {
            if (candidates[i] == end)
                continue;

            if (target > candidates[i]) {
                v.push_back(candidates[i]);
                combinationSum2(candidates, target - candidates[i], vv, v, i + 1);
                end = v.back();
                v.pop_back();
            } else if (target < candidates[i]) {
                return ;
            } else {
                v.push_back(candidates[i]);
                vv.push_back(v);
                return ;
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> vv;
        combinationSum2(candidates, target, vv, vector<int>(), 0);
        return vv;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v = {1,1};
    vector<vector<int>> vv = sol.combinationSum2(v, 1);

    for (auto &x : vv) {
        for (auto i : x)
            cout << i;
        cout << endl;
    }

    return 0;
}
