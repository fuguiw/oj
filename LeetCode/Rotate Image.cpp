#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n, t1, t2, ti, tj;
        
        n = matrix.size();

        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                ti = i;
                tj = j;
                t1 = matrix[ti][tj];
                for (int k = 0; k < 4; k++) {
                    t2 = ti;
                    ti = tj;
                    tj = n - t2 - 1;
                    t2 = matrix[ti][tj];
                    matrix[ti][tj] = t1;
                    t1 = t2;
                }
            }
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<int> > vv;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vv.push_back(v);
    v[0] = 5;
    v[1] = 6;
    v[2] = 7;
    v[3] = 8;
    vv.push_back(v);
    v[0] = 9;
    v[1] = 10;
    v[2] = 11;
    v[3] = 12;
    vv.push_back(v);
    v[0] = 13;
    v[1] = 14;
    v[2] = 15;
    v[3] = 16;
    vv.push_back(v);

    sol.rotate(vv);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cout << vv[i][j] << endl;

    return 0;
}
