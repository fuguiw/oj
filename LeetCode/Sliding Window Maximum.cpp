#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> v;
        for (int i = 0; i < nums.size(); ++i) {
            while (!dq.empty() && dq.back() < nums[i])
                dq.pop_back();
            if (!dq.empty() && i >= k && dq.front() == nums[i - k])
                dq.pop_front();
            dq.push_back(nums[i]);

            if (i >= k - 1)
                v.push_back(dq.front());
        }
        return v;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v{1,-1};
    v = sol.maxSlidingWindow(v, 1);
    for (int i : v)
        cout << i << endl;
    return 0;
}
