#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> signs;
        signs.push(1);
        signs.push(1);
        int rnt = 0;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                int num = 0;
                while (i < s.size() && isdigit(s[i]))
                    num = num * 10 + s[i++] - '0';

                rnt += signs.top() * num;
                signs.pop();
                i--;
            } else if (c == ')') {
                signs.pop();
            } else if (c != ' ') {
                signs.push(signs.top() * (c == '-' ? -1 : 1));
            }
        }

        return rnt;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s;

    while (cin >> s)
        cout << sol.calculate(s) << endl;

    return 0;
}

