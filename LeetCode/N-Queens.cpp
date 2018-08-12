#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int vr[44], vc[44], vs[44], vb[44];
    int num;

    void f(vector<vector<string> > &vv, vector<string> &v, int i) {
        ++i;
        int tr, tc, ts, tb;

        for (int j = 1; j <= num; j++) {
            if (!vr[i] && !vc[j] && !vs[i + j] && !vb[i + num - j]) {
                if (i == num) {
                    v[i - 1][j - 1] = 'Q';
                    vv.push_back(v);
                    v[i - 1][j - 1] = '.';
                } else {
                    tr = vr[i];
                    tc = vc[j];
                    ts = vs[i + j];
                    tb = vb[i + num - j];
                    vr[i] = vc[j] = vs[i + j] = vb[i + num - j] = 1;
                    v[i - 1][j - 1] = 'Q';

                    f(vv, v, i);

                    v[i - 1][j - 1] = '.';
                    vr[i] = tr;
                    vc[j] = tc;
                    vs[i + j] = ts;
                    vb[i + num -j] = tb;
                }
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        string s(n, '.');
        vector<string> v;
        vector<vector<string> > vv;

        for (int i = 0; i < n; i++)
            v.push_back(s);

        num = n;

        memset(vr, 0, sizeof(vr));
        memset(vc, 0, sizeof(vc));
        memset(vs, 0, sizeof(vs));
        memset(vb, 0, sizeof(vb));

        f(vv, v, 0);

        return vv;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<string> > vv;

    vv = sol.solveNQueens(1);
    vv = sol.solveNQueens(2);
    vv = sol.solveNQueens(3);
    vv = sol.solveNQueens(4);
    /* vv = sol.solveNQueens(5); */

    for (int i = 0; i < vv.size(); i++)
        for (int j = 0; j < vv[0].size(); j++)
            cout << vv[i][j] << endl;

    return 0;
}
