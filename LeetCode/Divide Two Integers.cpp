#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
    int divide_(long long dividend, long long divisor) {
        if (dividend < divisor)
            return 0;

        long long divisor_ = divisor;

        long long cnt = 1;
        while (divisor_ < dividend) {
            divisor_ <<= 1;
            cnt <<= 1;
        }

        long long ret = 0;
        while (dividend >= divisor) {
            if (dividend < divisor_) {
                divisor_ >>= 1;
                cnt >>= 1;
                continue;
            }

            dividend -= divisor_;
            ret += cnt;
        }

        return ret;
    }
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1 || divisor == 0)
            return INT_MAX;

        bool b = (dividend < 0) ^ (divisor < 0);
        if (b)
            return -divide_(fabs((long long)dividend), fabs((long long)divisor));
        else
            return divide_(fabs((long long)dividend), fabs((long long)divisor));
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    cout << sol.divide(2147483647, 1) << endl;
    return 0;
}
