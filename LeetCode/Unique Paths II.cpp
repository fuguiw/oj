#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int n, m;

		if (!(n = obstacleGrid.size()))
			return 0;
		m = obstacleGrid[0].size();
		int paths[m];

		memset(paths, 0, sizeof(paths));
		paths[0] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (obstacleGrid[i][j]) {
					paths[j] = 0;
					continue;
				}
				if (j) {
					paths[j] += paths[j - 1];
				}
			}
		}
		return paths[m - 1];
    }
};

int main()
{
	Solution sol;
	vector<vector<int> > Grid;
	vector<int> v;
	for (int i = 0; i < 3; i++) {
		Grid.push_back(v);
		for (int j = 0; j < 3; j++)
			Grid[i].push_back(0);
	}
	Grid[2][2] = 1;

	cout << sol.uniquePathsWithObstacles(Grid) << endl;
	return 0;
}
