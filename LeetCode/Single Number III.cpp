#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num = 0;
        for (int n : nums)
            num ^= n;

        int i;
        for (i = 0; i < 32; ++i)
            if (num & (1 << i))
                break;

        int num1 = 0;
        int num2 = 0;
        for (int n : nums) {
            if (n & (1 << i))
                num1 ^= n;
            else
                num2 ^= n;
        }

        return {num1, num2};
    }
};

