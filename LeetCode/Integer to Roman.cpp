#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> roman = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
vector<int> val = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

class Solution {
public:
    string intToRoman(int num) {
        string ret;

        for (int i = 12; i >= 0 && num; i--) {
            for (int j = 3; j > 0 && num; j--) {
                if (num >= val[i]) {
                    num -= val[i];
                    ret += roman[i];
                }
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int n;
    while (cin >> n)
        cout << sol.intToRoman(n) << endl;
    return 0;
}
