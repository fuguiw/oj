#include <iostream>
#include <string>
using namespace std;

class Solution {
    string rnt;

    int fac(int n) {
        int ret = 1;
        for (int i = 2; i <= n; i++)
            ret *= i;
        return ret;
    }

    void getPermutation(int n, int k, string s, int *v, int &cnt) {
        int f = fac(n - s.size());
        if (f < k - cnt) {
            cnt += f;
            return ;
        }

        if (s.size() == n) {
            cnt++;
            if (cnt == k) {
                rnt = s;
                return ;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (rnt.size() == n) return ;

            if (!v[i]) {
                v[i] = 1;
                getPermutation(n, k, s + static_cast<char>('0' + i), v, cnt);
                v[i] = 0;
            }
        }
    }

public:
    string getPermutation(int n, int k) {
        int v[10] = {};
        int cnt;
        rnt = "";
        getPermutation(n, k, string(), v, cnt);
        return rnt;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.getPermutation(9, 353955) << endl;

    return 0;
}
