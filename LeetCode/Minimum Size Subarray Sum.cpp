#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> sum(nums.size() + 1, 0);

        for (int i = 1; i < sum.size(); i++)
            sum[i] = sum[i - 1] + nums[i - 1];

        int ret = INT_MAX;
        for (int i = 0, j = 1; j < sum.size(); ) {
            if (sum[j] - sum[i] >= s) {
                ret = min(j - i, ret);
                i++;
            } else {
                j++;
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v;

    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(3);

    cout << sol.minSubArrayLen(7, v) << endl;

