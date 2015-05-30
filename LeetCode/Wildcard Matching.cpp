#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.size();
        int lenp = p.size();
        if (lenp == 0)
            return (lens == 0 ? true : false);

        int stars = count(p.begin(), p.end(), '*');
        if (lenp - stars > lens)
            return false;

        vector<vector<bool>> match(lens + 1, vector<bool>(lenp + 1, false));

        match[0][0] = true;

        for (int i = 0; i <= lens; i++) {
            for (int j = 1; j <= lenp; j++) {
                if (i == 0) {
                    if (p[j - 1] != '*')
                        break;
                    match[i][j] = true;
                }

                if (p[j - 1] == '?') {
                    match[i][j] = match[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    if (i == 1 && j == 1) match[i][j] = 1;
                    else match[i][j] = match[i][j - 1] || match[i - 1][j];
                } else {
                    match[i][j] = (match[i - 1][j - 1]) && (s[i - 1] == p[j - 1]);
                }
            }
        }

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
