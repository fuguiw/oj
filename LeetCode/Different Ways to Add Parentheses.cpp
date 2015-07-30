#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> rnt;

        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> rnt1 = diffWaysToCompute(input.substr(0, i));
                vector<int> rnt2 = diffWaysToCompute(input.substr(i + 1));

                for (auto n1 : rnt1) {
                    for (auto n2 : rnt2) {
                        if (input[i] == '+')
                            rnt.push_back(n1 + n2);
                        else if (input[i] == '-')
                            rnt.push_back(n1 - n2);
                        else if (input[i] == '*')
                            rnt.push_back(n1 * n2);
                    }
                }
            }
        }

        if (rnt.empty())
            rnt.push_back(atoi(input.c_str()));
        return rnt;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s("2*3-4*5");
    vector<int> v = sol.diffWaysToCompute(s);
    for (auto i : v)
        cout << i << endl;
    return 0;
}
