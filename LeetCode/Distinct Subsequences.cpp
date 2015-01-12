#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int ls = S.size();
        int lt = T.size();
        int cnt[lt + 1][ls + 1];

        if (lt > ls)
            return 0;

        memset(cnt, 0, sizeof(cnt));

        for (int i = 0; i <= ls; i++)
            cnt[0][i] = 1;

        for (int i = 1; i <= lt; i++) {
            for (int j = 1; j <= ls; j++) {
                cnt[i][j] = cnt[i][j - 1]
                    + (T[i - 1] == S[j - 1] ? cnt[i - 1][j - 1] : 0);
            }
        }

        return cnt[lt][ls];
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.numDistinct("ddd", "d") << endl;

    return 0;
}
