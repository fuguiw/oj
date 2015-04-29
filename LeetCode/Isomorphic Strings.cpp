#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int vs[256], vt[256];
        memset(vs, 0, sizeof(vs));
        memset(vt, 0, sizeof(vt));

        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (vs[s[i]] != vt[t[i]])
                return false;
            vs[s[i]] = vt[t[i]] = i + 1;
        }

        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    cout << sol.isIsomorphic("13", "42") << endl;
    return 0;
}
