#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
        int n = num.size();
        int d[n];

        int rnt = 0;
        for (int i = 0; i < n; ++i) {
            int tmp = 0;
            if (i - 2 >= 0)
                tmp = d[i - 2];
            if (i - 3 >= 0)
                tmp = max(tmp, d[i - 3]);

            d[i] = tmp + num[i];
            cout << d[i] << endl;
            rnt = max(rnt, d[i]);
        }

        return rnt;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> num{1,2,3,4,5, 6,7};

    cout << sol.rob(num) << endl;

    return 0;
}
