#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(int a, int b)
{
    string s1 = to_string(a);
    string s2 = to_string(b);

    if (s1 + s2 > s2 + s1)
        return true;
    else
        return false;
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        string ret;
        int len = num.size();

        sort(num.begin(), num.end(), cmp);

        if (num[0] == 0)
            return to_string(0);

        for (int i = 0; i < len; i++) {
            cout << num[i] << endl;
            ret += to_string(num[i]);
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v;

    v.push_back(0);
    v.push_back(0);
    /* v.push_back(30); */
    /* v.push_back(34); */
    /* v.push_back(5); */
    /* v.push_back(9); */

    cout << sol.largestNumber(v) << endl;

    return 0;
}
