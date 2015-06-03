#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row, col;
        row = matrix.size();
        if (row == 0) return 0;
        col = matrix[0].size();

        vector<vector<int>> cnt(row, vector<int>(col, 0));
        for (int j = 0; j < col; j++) 
            for (int i = 0; i < row; i++)
                if (matrix[i][j] == '1') 
                    cnt[i][j] = 1 + (i > 0 ? cnt[i - 1][j] : 0);

        int rnt = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0')
                    continue;

                int minc = INT_MAX;
                for (int k = j; k < col && matrix[i][k] == '1'; k++) {
                    minc = min(minc, cnt[i][k]);
                    if (minc < (k - j + 1))
                        break;
                    rnt = max(rnt, (k - j + 1) * (k - j + 1));
                }
            }
        }

        return rnt;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<char>> matrix;
    vector<char> v;
    v = {'1','0','1','1','1'};
    matrix.push_back(v);
    v = {'1','0','1','1','1'};
    matrix.push_back(v);
    v = {'1','1','1','1','1'};
    matrix.push_back(v);
    v = {'1','0','0','1','0'};
    matrix.push_back(v);

    cout << sol.maximalSquare(matrix) << endl;

    return 0;
}
