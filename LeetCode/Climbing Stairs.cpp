#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
		int p1, p2, rnt;
		p1 = 1;
		p2 = 2;
		if (n < 3) return n;
		for (int i = 3; i <= n; i++) {
			rnt = p1 + p2;
			p1 = p2;
			p2 = rnt;
		}
		return rnt;
    }
};

int main()
{
	Solution sol;
	cout << sol.climbStairs(4) << endl;
	return 0;
}
