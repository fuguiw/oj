#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, int> m;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            auto it = m.lower_bound(nums[i] - t);
            for (; it != m.end(); it++)
                if (it->first - nums[i] <= t)
                    return true;
                else
                    break;

            ++m[nums[i]];

            if (i >= k)
                if (--m[nums[i - k]] == 0)
                    m.erase(nums[i - k]);
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v{3,6,0,4};
    cout << sol.containsNearbyAlmostDuplicate(v, 0, 2) << endl;
    return 0;
}
