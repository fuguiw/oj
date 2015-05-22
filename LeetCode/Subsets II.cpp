#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> vv(1, vector<int>());

        sort(nums.begin(), nums.end());

        int len = nums.size();
        int pre;
        for (int i = 0; i < len; i++) {
            int len_ = vv.size();
            int j;
            if (i > 0 && nums[i] == nums[i - 1])
                j = pre;
            else
                j = 0;
            pre = len_;
            vector<int> tmp;
            for (; j < len_; j++) {
                tmp = vv[j];
                tmp.push_back(nums[i]);
                vv.push_back(tmp);
            }
        }

        return vv;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v{1,2,2};
    vector<vector<int>> vv = sol.subsetsWithDup(v);

    for (auto x : vv) {
        for (auto i : x)
            cout << i;
        cout << endl;
    }
    
    return 0;
}
