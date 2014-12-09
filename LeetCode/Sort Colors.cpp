#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
		int cnt[3];
		int i, j, k;

		memset(cnt, 0, sizeof(cnt));

		for (i = 0; i < n; i++)
			++cnt[A[i]];

		for (i = k = 0; i < 3; i++)
			for (j = 0; j < cnt[i]; j++)
				A[k++] = i;
    }
};

int main(int argc, char *argv[])
{
	Solution sol;

	int A[] = {1,1};

	sol.sortColors(A, 2);

	for (int i = 0; i < 2; i++)
		cout << A[i] << endl;

	return 0;
}
