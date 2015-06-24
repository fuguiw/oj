#include <iostream>
using namespace std;

class Solution {
    double bPower(double base, int exponent) {
        if (exponent == 0)
            return 1;
        if (exponent == 1)
            return base;
        if (exponent == 2)
            return base * base;

        int tmp = exponent >> 1;
        return bPower(base, tmp) * bPower(base, exponent - tmp); 
    }

public:
    double Power(double base, int exponent) {
        bool is_minus = exponent < 0;
        if (is_minus)
            exponent = -exponent;
        double ret = bPower(base, exponent);
        if (is_minus)
            return 1 / ret;
        else
            return ret;
        
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    double base;
    int exponent;
    while (cin >> base >> exponent)
        cout << sol.Power(base, exponent) << endl;

    return 0;
}
