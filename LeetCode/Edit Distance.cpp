#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        vector<vector<int>> d(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 0; i <= len1; i++)
            d[i][0] = i;
        for (int i = 0; i <= len2; i++)
            d[0][i] = i;

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                d[i][j] = min(d[i - 1][j], d[i][j  - 1]) + 1;
                d[i][j] = min(d[i][j], d[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1));
            }
        }

        return d[len1][len2];
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string a, b;
    while (cin >> a >> b)
        cout << sol.minDistance(a, b) << endl;
    return 0;
}

