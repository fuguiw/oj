#include<iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
		int left, right, mid;

		left = 0;
		right = n - 1;

		while (left <= right) {
			mid = (left + right) / 2;

			if (A[mid] == target)
				return mid;

			if (A[mid] < target) {
				if (target <= A[n - 1]) {
					left = mid + 1;
				} else {
					if (A[mid] <= A[n - 1])
						right = mid - 1;

					if (A[mid] >= A[0])
						left = mid + 1;
				}
			} else {
				if (target >= A[0]) {
					right = mid - 1;
				} else {
					if (A[mid] <= A[n - 1])
						right = mid - 1;

					if (A[mid] >= A[0])
						left = mid + 1;
				}
			}

		}

		return -1;
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	int a[44];
	int n;

	while (cin >> n) {
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << sol.search(a, n, 4) << endl;
	}

	return 0;
}
