#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int> > rnt;
    vector<int> v;

    void combine(int n, int k, int i, int cnt) {
        if (cnt == k) {
            rnt.push_back(v);
            return ;
        }

        for (int j = i + 1; j <= n - (k - cnt) + 1; j++) {
            v.push_back(j);
            combine(n, k, j, cnt + 1);
            v.pop_back();
        }
    }

public:
    vector<vector<int> > combine(int n, int k) {
        rnt.clear();
        v.clear();

        combine(n, k, 0, 0);

        return rnt;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<int> > v;
    int n, k;

    while (cin >> n >> k) {
        v = sol.combine(n, k);

        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

