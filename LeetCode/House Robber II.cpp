#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];

        int d[len];
        d[0] = nums[0];
        d[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len; i++)
            d[i] = max(d[i - 1], d[i - 2] + nums[i]);

        int ret = d[len - 1];
        d[0] = max(d[len - 1], d[len - 2] + nums[0]);
        d[1] = max(d[0], d[len - 1] + nums[1]);
        for (int i = 2; i < len; i++)
            d[i] = max(d[i - 1], d[i - 2] + nums[i]);

        return min(ret, d[len - 1] - ret);
    }
};
