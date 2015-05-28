#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;

        while (left < right) {
            int mid = (left + right) / 2;
            if (mid != 0 && (x / mid == mid))
                return mid;
            else if (mid != 0 && (x / mid < mid))
                right = mid - 1;
            else
                left = mid + 1;
        }

        if (left != 0 && (x / left) < left)
            return left - 1;
        return left;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int n;
    while (cin >> n)
        cout << sol.mySqrt(n) << endl;
    return 0;
}
