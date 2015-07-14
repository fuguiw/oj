#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        if (str.empty())
            return 0;

        long long num = 0;
        int sign = 1;
        for (int i = 0; i < str.size(); ++i) {
            if (i == 0 && str[i] == '-') {
                sign = -1;
            } else if (i == 0 && str[i] == '+') {
                sign = 1;
            } else if (isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
            } else {
                return 0;
            }

            if (num * sign > INT_MAX || num * sign < INT_MIN)
                return 0;
        }

        return num * sign;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s;
    while (cin >> s)
        cout << sol.StrToInt(s) << endl;
    return 0;
}
