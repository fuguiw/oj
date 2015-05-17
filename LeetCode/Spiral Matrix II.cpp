#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vv(n, vector<int>(n));

        int num = 1;
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i; j++)
                vv[i][j] = num++;

            for (int j = i + 1; j < n - i; j++)
                vv[j][n - 1 - i] = num++;

            for (int j = n - 2 - i; j >= i; j--)
                vv[n - 1 - i][j] = num++;

            for (int j = n - 2 - i; j > i; j--)
                vv[j][i] = num++;
        }

        if (n % 2)
            vv[n / 2][n / 2] = num;

        return vv;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> vv = sol.generateMatrix(4);

    for (auto &v : vv) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
