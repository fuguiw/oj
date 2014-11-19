#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
		int rnt = 0;

		if (n == 1)
			return 1;
		
		rnt += 2 * numTrees(n - 1);
		for (int i = 2; i < n; i++) {
			rnt += numTrees(i - 1) * numTrees(n - i);
		}

		return rnt;
    }
};

int main()
{
	Solution sol;
	int n;
	while (cin >> n)
		cout << sol.numTrees(n) << endl;
	return 0;
}

