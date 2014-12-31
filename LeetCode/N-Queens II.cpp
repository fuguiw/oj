#include <iostream>
using namespace std;

class Solution {
private:
    int *vr, *vc, *vs, *vb;
    int rnt;
    int num;

    void f(int i) {
        ++i;
        int tr, tc, ts, tb;

        for (int j = 1; j <= num; j++) {
            if (!vr[i] && !vc[j] && !vs[i + j] && !vb[i + num - j]) {
                if (i == num) {
                    ++rnt;
                } else {
                    tr = vr[i];
                    tc = vc[j];
                    ts = vs[i + j];
                    tb = vb[i + num - j];
                    vr[i] = vc[j] = vs[i + j] = vb[i + num - j] = 1;

                    f(i);

                    vr[i] = tr;
                    vc[j] = tc;
                    vs[i + j] = ts;
                    vb[i + num -j] = tb;
                }
            }
        }
    }

public:
    int totalNQueens(int n) {
        num = n;
        rnt = 0;

        vr = (int *)malloc((num + 1) * sizeof(int));
        vc = (int *)malloc((num + 1) * sizeof(int));
        vs = (int *)malloc((num * 2) * sizeof(int));
        vb = (int *)malloc((num * 2) * sizeof(int));

        memset(vr, 0, (num + 1) * sizeof(int));
        memset(vc, 0, (num + 1) * sizeof(int));
        memset(vs, 0, (num * 2) * sizeof(int));
        memset(vb, 0, (num * 2) * sizeof(int));

        f(0);

        return rnt;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int n;

    while (cin >> n)
        cout << sol.totalNQueens(n) << endl;

    return 0;
}
