#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";

        string res;
        if ((numerator < 0) ^ (denominator < 0))
            res += "-";

        long long num = numerator;
        long long den = denominator;
        num = fabs(num);
        den = fabs(den);
        long long quo = num / den;
        num -= den * quo;
        res += to_string(quo);
        if (num > 0)
            res += ".";

        unordered_map<long long, int> m;
        num *= 10;
        int len = res.size();
        while (num) {
            if (m.find(num) == m.end()) {
                m[num] = len;
            } else {
                res = res.substr(0, m[num]) + "(" + res.substr(m[num], len - m[num]) + ")";
                break;
            }

            if (num < den) {
                num *= 10;
                res += "0";
                len++;
                continue;
            }

            if (num > den) {
                int tmp = num / den;
                num -= tmp * den;
                res += to_string(tmp);
                num *= 10;
                len++;
            }
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.fractionToDecimal(-2147483648, 1) << endl;

    return 0;
}
