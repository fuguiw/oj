#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int r[4] = {1,-1,0,0};
    int c[4] = {0,0,1,-1};
    int rnt;
    void f(vector<vector<char>> &grid, int i, int j)
    {
        if (grid[i][j] == '0')
            return ;

        grid[i][j] = '0';
        for (int k = 0; k < 4; k++) {
            int ti = i + r[k];
            if (ti < 0 || ti >= grid.size())
                continue;
            int tj = j + c[k];
            if (tj < 0 || tj >= grid[i].size())
                continue;

            f(grid, ti, tj);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        rnt = 0;

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j) 
                if (grid[i][j] == '1') {
                    ++rnt;
                    f(grid, i, j);
                }

        return rnt;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<char>> grid;
    vector<char> v{'1', '0'};
    grid.push_back(v);
    v[0] = '0';
    v[1] = '1';
    grid.push_back(v);

    cout << sol.numIslands(grid) << endl;

    return 0;
}
