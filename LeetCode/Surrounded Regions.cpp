#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char> > &board) {
		int i, j, r, c, tr, tc;
		int n = board.size();
		if (!n) return;
		int m = board[0].size();
		int visit[n][m];
		queue<int> q;

		int move[2][4] = {
			1, -1, 0, 0,
			0, 0, 1, -1
		};

		memset(visit, 0, sizeof(visit));

		for (i = 0; i < m; i++) {
			if (board[0][i] == 'O') {
				q.push(0);
				q.push(i);
				visit[0][i] = 1;
			}
			if (board[n - 1][i] == 'O') {
				q.push(n - 1);
				q.push(i);
				visit[n - 1][i] = 1;
			}
		}
		for (i = 0; i < n; i++) {
			if (board[i][0] == 'O') {
				q.push(i);
				q.push(0);
				visit[i][0] = 1;
			}
			if (board[i][m - 1] == 'O') {
				q.push(i);
				q.push(m - 1);
				visit[i][m - 1] = 1;
			}
		}

		while (!q.empty()) {
			r = q.front();
			q.pop();
			c = q.front();
			q.pop();

			for (i = 0; i < 4; i++) {
				tr = r + move[0][i];
				tc = c + move[1][i];

				if (tr < 0 || tr >= n || tc < 0 || tc >= m) continue;

				if (board[tr][tc] == 'O' && !visit[tr][tc]) {
					q.push(tr);
					q.push(tc);
					visit[tr][tc] = 1;
				}
			}
		}

		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++)
				if (!visit[i][j])
					board[i][j] = 'X';
		}
    }
};

int main(int argc, char *argv[])
{
	int i, j;
	Solution sol;
	vector<vector<char> > v;
	vector<char> v1;

	for (j = 0; j < 5; j++)
		v1.push_back('#');

	for (i = 0; i < 4; i++)
		v.push_back(v1);

	v[1][1] = v[1][2] = v[2][2] = v[3][1] = 'O';

	sol.solve(v);

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++)
			cout << v[i][j];
		cout << endl;
	}

	return 0;
}
