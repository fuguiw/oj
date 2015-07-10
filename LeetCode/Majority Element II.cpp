#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;

        int n1, n2;
        int c1, c2;
        c1 = c2 = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (c1 && nums[i] == n1) {
                c1++;
            } else if (c2 && nums[i] == n2) {
                c2++;
            } else {
                if (c1 == 0) {
                    n1 = nums[i];
                    c1 = 1;
                } else if (c2 == 0) {
                    n2 = nums[i];
                    c2 = 1;
                } else {
                    --c1;
                    --c2;
                }
            }
        }

        int cnt1, cnt2;
        cnt1 = cnt2 = 0;
        for (int i = 0; i < len; i++) {
            if (c1 && n1 == nums[i])
                ++cnt1;
            if (c2 && n2 == nums[i])
                ++cnt2;
        }
        if (cnt1 > len / 3)
            v.push_back(n1);
        if (cnt2 > len / 3)
            v.push_back(n2);

        return v;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v = {1,2,4,3,5};
    v = sol.majorityElement(v);
    for (auto n : v)
        cout << n << endl;
    return 0;
}
