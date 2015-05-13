#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
    bool exist(vector<vector<char>>& board, int r, int c, string& word, int i) {
        if (i == word.size())
            return true;

        char ch = board[r][c];
        board[r][c] = ' ';

        if (r > 0 && board[r - 1][c] == word[i]) {
            if (exist(board, r - 1, c, word, i + 1))
                return true;
        }

        if (c > 0 && board[r][c - 1] == word[i]) {
            if (exist(board, r, c - 1, word, i + 1))
                return true;
        }

        if (r < board.size() - 1 && board[r + 1][c] == word[i]) {
            if (exist(board, r + 1, c, word, i + 1))
                return true;
        }

        if (c < board[r].size() - 1 && board[r][c + 1] == word[i]) {
            if (exist(board, r, c + 1, word, i + 1))
                return true;
        }
        
        board[r][c] = ch;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty())
            return false;

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] == word[0]) {
                    char ch = board[i][j];
                    board[i][j] = ' ';
                    if (exist(board, i, j, word, 1))
                        return true;
                    board[i][j] = ch;
                }
        
        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<char>> vv;
    vector<char> v{'C', 'A', 'A'};
    vv.push_back(v);
    v = {'A', 'A', 'A'};
    vv.push_back(v);
    v = {'B', 'C', 'D'};
    vv.push_back(v);

    cout << sol.exist(vv, "AAB") << endl;
    return 0;
}
