#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    void Permutation(string str, int idx, vector<string>& ret, vector<bool>& v, string& s)
    {
        if (idx == str.size()) {
            ret.push_back(s);
            return ;
        }

        for (int i = 0; i < str.size(); i++) {
            if (i > 0 && !v[i - 1] && str[i] == str[i - 1])
                continue;
            if (!v[i]) {
                v[i] = true;
                s[idx] = str[i];
                Permutation(str, idx + 1, ret, v, s);
                v[i] = false;
            }
        }
    }

public:
    vector<string> Permutation(string str) {
        sort(str.begin(), str.end());
        string s(str);
        vector<string> ret;
        vector<bool> v(str.size(), false);

        if (str.size())
            Permutation(str, 0, ret, v, s);

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    vector<string> v = sol.Permutation("");

    for (auto s : v)
        cout << s << endl;

    return 0;
}
