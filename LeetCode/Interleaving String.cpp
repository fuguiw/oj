#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();

        vector<vector<bool>> v(len1 + 1, vector<bool>(len2 + 1, false));
        v[0][0] = true;
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                if (i)
                    v[i][j] = v[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
                if (j)
                    v[i][j] = v[i][j] || (v[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
            }
        }

        if (len1 + len2 == len3)
            return v[len1][len2];
        else
            return false;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s1, s2, s3;
    while (cin >> s2 >> s3)
        cout << sol.isInterleave("", s2, s3) << endl;

    return 0;
}

