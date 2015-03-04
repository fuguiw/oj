#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(int *nums, int n, int k) {
        for (; k %= n; n -= k) {
            for (int i = 0; i < k; i++) {
                swap(*nums++, nums[n - k]);
            }
        }
    }
};

int main(int argc, char *argv[])
{
    int nums[] = {1,2,3};
    Solution sol;
    int i;
    sol.rotate(nums, 3, 1);
    for (i = 0; i < 3; i++)
        printf("%d\n", nums[i]);
    return 0;
}

