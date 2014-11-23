#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
		int pos[n];
		int neg[n];
		int rnt;

		pos[0] = neg[0] = rnt = A[0]; 
		for (int i = 1; i < n; i++) {
			pos[i] = max(max(A[i], pos[i - 1] * A[i]), neg[i - 1] * A[i]);
			neg[i] = min(min(A[i], pos[i - 1] * A[i]), neg[i - 1] * A[i]);
			rnt = max(rnt, pos[i]);
		}
		return rnt;
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	int a[] = {2,3,-2,4};
	cout << sol.maxProduct(a, 4) << endl;
	return 0;
}
