#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> signs;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                int num = 0;
                while (i < s.size() && isdigit(s[i]))
                    num = num * 10 + (s[i++] - '0');

                if (!signs.empty()) {
                    if (signs.top() == '*') {
                        int a = nums.top();
                        nums.pop();
                        nums.push(a * num);
                        signs.pop();
                    } else if (signs.top() == '/') {
                        int a = nums.top();
                        nums.pop();
                        nums.push(a / num);
                        signs.pop();
                    } else {
                        nums.push(num);
                    }
                } else {
                    nums.push(num);
                }
                --i;
            } else if (!isspace(c)) {
                if (c == '-' || c == '+') {
                    if (!signs.empty()) {
                        char sign = signs.top();
                        signs.pop();
                        int a = nums.top();
                        nums.pop();
                        int b = nums.top();
                        nums.pop();
                        if (sign == '+')
                            nums.push(a + b);
                        else
                            nums.push(b - a);
                    }
                }
                signs.push(c);
            }
        }

        if (!signs.empty()) {
            char sign = signs.top();
            signs.pop();
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            if (sign == '+')
                nums.push(a + b);
            else
                nums.push(b - a);
        }


        return nums.top();
    }
};

int main(int argc, char *argv[])
{
    string s;
    Solution sol;
    while (getline(cin, s))
        cout << sol.calculate(s) << endl;
    return 0;
}

