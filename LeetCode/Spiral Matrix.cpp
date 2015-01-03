#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int cnt;
        int row, col;
        vector<int> rnt;
        int i, j, ni, nj;

        row = matrix.size();
        if (!row) return rnt;
        col = matrix[0].size();
        int v[row + 2][col + 2];

        cnt = row * col;
        memset(v, 0, sizeof(v));

        for (i = 1; i <= col; i++)
            v[0][i] = v[row + 1][i] = 1;
        for (i = 1; i <= row; i++)
            v[i][0] = v[i][col + 1] = 1;

        i = j = 1;
        ni = 0;
        nj = 1;
        while (cnt--) {
            rnt.push_back(matrix[i - 1][j - 1]);
            v[i][j] = 1;

            if (v[i + ni][j + nj]) {
                if (ni == 0 && nj == 1) {
                    ni = 1;
                    nj = 0;
                } else if (ni == 1 && nj == 0) {
                    ni = 0;
                    nj = -1;
                } else if (ni == 0 && nj == -1) {
                    ni = -1;
                    nj = 0;
                } else if (ni == -1 && nj == 0) {
                    ni = 0;
                    nj = 1;
                }
            }

            i += ni;
            j += nj;
        }

        return rnt;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<int> > m;
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    m.push_back(v);

    v = sol.spiralOrder(m);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;

    return 0;
}
