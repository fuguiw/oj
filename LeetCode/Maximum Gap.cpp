#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void r_sort(vector<int> &num) {
        int len = num.size();
        int c[11];
        int w = 10;
        int m = 1;
        int tmp;
        int exit;
        int i;
        vector<int> v(num);

        for (exit = 0; !exit; ) {
            exit = 1;
            memset(c, 0, sizeof(c));
            for (i = 0; i < len; i++) {
                if (num[i] / m) exit = 0;

                tmp = num[i] % w / m;
                c[tmp]++;
            }

            for (i = 1; i < 10; i++)
                c[i] += c[i - 1];

            for (i = len - 1; i >= 0; i--) {
                tmp = num[i] % w / m;
                v[--c[tmp]] = num[i];
            }

            num = v;
            w *= 10;
            m *= 10;
        }
    }

    int maximumGap(vector<int> &num) {
        int len = num.size();
        int rnt = 0;

        r_sort(num);

        for (int i = 1; i < len; i++)
            rnt = max(rnt, num[i] - num[i - 1]);

        return rnt;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v;

    v.push_back(1);
    /* v.push_back(1000); */
    v.push_back(7);
    v.push_back(4);
    v.push_back(9);

    cout << sol.maximumGap(v) << endl;

    return 0;
}
