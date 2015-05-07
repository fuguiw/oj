#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();

        for (int i = len - 1; i >= 0; i--) {
            for (int j = len - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    sort(nums.begin() + i + 1, nums.end());
                    return ;
                }
            }
        }

        sort(nums.begin(), nums.end());
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);

    sol.nextPermutation(v);

    for (auto i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}


