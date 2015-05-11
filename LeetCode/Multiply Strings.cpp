#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> mul(num1.size() + num2.size() - 1, 0);

        for (int i = num1.size() - 1; i >= 0; i--) {
            int k = num2.size() + i - 1;
            for (int j = num2.size() - 1; j >= 0; j--) {
                mul[k--] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int carry = 0;
        for (int i = num1.size() + num2.size() - 2; i >= 0; i--) {
            mul[i] += carry;
            carry = mul[i] / 10;
            mul[i] = mul[i] % 10 + '0';
        }

        if (carry)
            mul.insert(mul.begin(), carry + '0');

        vector<int>::iterator it;
        for (it = mul.begin(); it != mul.end() - 1; it++) {
            if (*it != '0')
                break;
        }
        mul.erase(mul.begin(), it);

        return string(mul.begin(), mul.end());
    }
};

int main(int argc, char *argv[])
{
    string a, b;
    Solution sol;

    while (cin >> a >> b)
        cout << sol.multiply(a, b) << endl;

    return 0;
}

