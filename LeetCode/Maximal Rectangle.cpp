#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		int n, m;

		n = matrix.size();
		if (!n) 
			return 0;
		m = matrix[0].size();

		int h[m];
		int minH;
		int rnt = 0;

		memset(h, 0, sizeof(h));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == '0') {
					h[j] = 0;
				} else {
					++h[j];
				}
			}
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == '0')
					continue;
				minH = h[j];
				for (int k = j; k < m; k++) {
					if (matrix[i][k] == '0') {
						break;
					}
					minH = min(minH, h[k]);
					rnt = max(rnt, minH * (k - j + 1));
				}
			}
		}
		return rnt;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	vector<char> row;
	vector<vector<char> > matrix;

	row.push_back('0');
	row.push_back('1');
	row.push_back('1');
	matrix.push_back(row);
	row[0] = '1';
	matrix.push_back(row);

	cout << sol.maximalRectangle(matrix) << endl;

	return 0;
}
