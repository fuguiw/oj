#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<int> v(len + 1, 0);

        for (int i = 0; i <= len; i++)
            v[i] = i - 1;

        for (int i = 1; i <= len; i++) {
            int before, after;
            before = after = i;
            for (; after < len && s[after] == s[after - 1]; after++)
                v[after] = min(v[after], v[before - 1] + 1);
            v[after] = min(v[after], v[before - 1] + 1);

            while (before > 1 && after < len && s[before - 2] == s[after]) {
                --before;
                ++after;
                v[after] = min(v[after], v[before - 1] + 1);
            }
            v[after] = min(v[after], v[before - 1] + 1);
        }

        return max(0, v[len]);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s;
    while (cin >> s)
        cout << sol.minCut(s) << endl;
    
    return 0;
}
