#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
		vector<vector<int> > rows;
		vector<int> row;
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0 || j == i) {
					row.push_back(1);
				} else {
					vector<vector<int> >::iterator tmp = rows.begin();
					vector<int> t = *(tmp + i - 1);
					row.push_back(t[j - 1] + t[j]);
				}
			}
			rows.push_back(row);
			row.clear();
		}
		return rows;
    }
};

int main()
{
	int n;
	vector<vector<int> > rows;
	vector<int> row;
	vector<int>::iterator it;
	while (cin >> n) {
		Solution sol;
		rows = sol.generate(n);
		for (int i = 0; i < n; i++) {
			row = rows[i];
			for (it = row.begin(); it < row.end(); it++)
				cout << *it << " ";
			cout << endl;	
		}
	}
	return 0;
}
