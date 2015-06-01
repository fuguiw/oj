#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.size();
        int lenp = p.size();

        vector<vector<bool>> match(lens + 1, vector<bool>(lenp + 1, false));
        match[0][0] = true;

        for (int i = 2; i <= lenp; i+=2)
            if (match[0][i - 2] && p[i - 1] == '*')
                match[0][i] = true;
            else
                break;

        for (int i = 1; i <= lens; i++) {
            for (int j = 1; j <= lenp; j++) {
                if (p[j - 1] == '*') {
                    match[i][j] = match[i][j - 2]
                        || (match[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    match[i][j] = match[i - 1][j - 1]
                        && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }

        /* for (int i = 0; i <= lens; i++) { */
        /*     for (int j = 1; j <= lenp; j++) */
        /*         cout << match[i][j]; */
        /*     cout << endl; */
        /* } */

        return match[lens][lenp];
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s, p;
    while (cin >> s >> p)
        cout << sol.isMatch(s, p) << endl;
    return 0;
}

