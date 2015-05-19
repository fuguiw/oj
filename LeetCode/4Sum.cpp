#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    void twoSum(vector<int> &nums, int target, vector<int> &v, vector<vector<int>> &vv, int left) {
        int l = left;
        int r = nums.size() - 1;

        while (l < r) {
            if (l > left && nums[l] == nums[l - 1]) {
                l++;
                continue;
            }

            if (r < nums.size() - 1 && nums[r] == nums[r + 1]) {
                r--;
                continue;
            }

            if (nums[l] + nums[r] == target) {
                v[2] = nums[l];
                v[3] = nums[r];
                vv.push_back(v);
            }

            nums[l] + nums[r] > target ? r-- : l++;
        }
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int len = nums.size();
        vector<int> v(4);
        vector<vector<int>> vv;

        for (int i = 0; i < len - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            v[0] = nums[i];
            for (int j = i + 1; j < len - 2; j++) {
                if (i == j || (j > i + 1 && nums[j] == nums[j - 1])) 
                    continue;
                v[1] = nums[j];
                twoSum(nums, target - nums[i] - nums[j], v, vv, j + 1);
            }
        }

        return vv;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v = {0, 0, 0, 0};
    vector<vector<int>> vv = sol.fourSum(v, 0);

    for (auto &r : vv) {
        for (auto i : r)
            cout << i;
        cout << endl;
    }

    return 0;
}
