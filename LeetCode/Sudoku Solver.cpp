#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void solveSudoku(vector<vector<char>> &board, vector<vector<char>> &sol, 
            vector<vector<bool>> &row, vector<vector<bool>> &col, vector<vector<bool>> &block, int n) {
        if (n == 81) {
            board.swap(sol);
            return ;
        }

        int i = n / 9;
        int j = n % 9;
        int nb = i / 3 * 3 + j / 3;

        if (board[i][j] != '.')
            solveSudoku(board, sol, row, col, block, n + 1);

        for (int k = 1; k <= 9 && board[i][j] == '.'; k++) {
            if (row[i][k] == false && col[j][k] == false && block[nb][k] == false) {
                row[i][k] = col[j][k] = block[nb][k] = true;
                sol[i][j] = '0' + k;
                solveSudoku(board, sol, row, col, block, n + 1);
                row[i][k] = col[j][k] = block[nb][k] = false;
            }
        }
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(10, false));
        vector<vector<bool>> col(9, vector<bool>(10, false));
        vector<vector<bool>> block(9, vector<bool>(10, false));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                int n = board[i][j] - '0';
                int nb = i / 3 * 3 + j / 3;
                row[i][n] = col[j][n] = block[nb][n] = true;
            }
        }

        vector<vector<char>> sol(board);
        solveSudoku(board, sol, row, col, block, 0);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<char>> board;
    vector<char> v;
    v = {'5','3','.','.','7','.','.','.','.'};
    board.push_back(v);
    v = {'6','.','.','1','9','5','.','.','.'};
    board.push_back(v);
    v = {'.','9','8','.','.','.','.','6','.'};
    board.push_back(v);
    v = {'8','.','.','.','6','.','.','.','3'};
    board.push_back(v);
    v = {'4','.','.','8','.','3','.','.','1'};
    board.push_back(v);
    v = {'7','.','.','.','2','.','.','.','6'};
    board.push_back(v);
    v = {'.','6','.','.','.','.','2','8','.'};
    board.push_back(v);
    v = {'.','.','.','4','1','9','.','.','5'};
    board.push_back(v);
    v = {'.','.','.','.','8','.','.','7','9'};
    board.push_back(v);

    sol.solveSudoku(board);
    
    for (auto &v : board) {
        for (auto c : v)
            cout << c;
        cout << endl;
    }

    return 0;
}
