#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        int col;
        if (row)
            col = matrix[0].size();

        vector<int> v;
        int layers = min(ceil(row / 2.0), ceil(col / 2.0));
        for (int k = 0; k < layers; k++) {
            int i, j;
            for (i = j = k; j < col - k; j++)
                v.push_back(matrix[i][j]);

            for (i = k + 1, j = col - k - 1; i < row - k; i++)
                v.push_back(matrix[i][j]);

            for (i = row - 1 - k, j = col - 2 - k; (row - 1 - k != k) && j >= k; j--)
                v.push_back(matrix[i][j]);

            for (i = row - 2 - k, j = k; (col - 1 - k != k) && i > k; i--)
                v.push_back(matrix[i][j]);
        }

        return v;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<int>> matrix;
    vector<int> v = {1,2,3,4};
    matrix.push_back(v);
    v = {5,6,7,8};
    matrix.push_back(v);
    v = sol.printMatrix(matrix);

    for (int i : v)
        cout << i << endl;

    return 0;
}
