#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    static const vector<string> m;

    void letterCombinations(string &digits, string &str, vector<string> &v, int i) {
        if (i == digits.size()) {
            if (i != 0)
                v.push_back(str);
            return ;
        }

        int num = digits[i] - '0';
        for (int j = 0; j < m[num].size(); j++) {
            str[i] = m[num][j];
            letterCombinations(digits, str, v, i + 1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        string str(digits.size(), ' ');
        letterCombinations(digits, str, v, 0);
        return v;
    }
};

const vector<string> Solution::m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main(int argc, char *argv[])
{
    Solution sol;
    string s("23");
    vector<string> v = sol.letterCombinations(s);
    for (auto str : v)
        cout << str << endl;
    return 0;
}

