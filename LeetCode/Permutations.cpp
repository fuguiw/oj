#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> v;
    vector<vector<int> > vv;

    void f(vector<int> &num, int *visit, int n) {
        int len = num.size();

        if (n == len) {
            vv.push_back(v);
            return ;
        }

        for (int i = 0; i < len; i++) {
            if (!visit[i]) {
                v.push_back(num[i]);
                visit[i] = 1;
                f(num, visit, n + 1);
                visit[i] = 0;
                v.pop_back();
            }
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        int len = num.size();
        int visit[len];

        memset(visit, 0, sizeof(visit));

        f(num, visit, 0);

        return vv;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v;
    vector<vector<int> > vv;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vv = sol.permute(v);

    for (int i = 0; i < vv.size(); i++)
        for (int j = 0; j < vv[0].size(); j++)
            cout << vv[i][j] << endl;

    return 0;
}
