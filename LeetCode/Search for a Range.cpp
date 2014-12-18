#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
		int left1, left2, right1, right2, mid1, mid2;
		vector<int> range;

		left1 = left2 = 0;
		right1 = right2 = n - 1;

		while (left1 <= right1 || left2 <= right2) {
			mid1 = (left1 + right1) / 2;
			mid2 = (left2 + right2) / 2;

			if (left1 <= right1) {
				if (A[mid1] >= target) {
					right1 = mid1 - 1;
				} else {
					left1 = mid1 + 1;
				}
			}

			if (left2 <= right2) {
				if (A[mid2] > target) {
					right2 = mid2 - 1;
				} else {
					left2 = mid2 + 1;
				}
			}
		}

		if (A[right1 + 1] == target) {
			range.push_back(right1 + 1);
			range.push_back(left2 - 1);
		} else {
			range.push_back(-1);
			range.push_back(-1);
		}

		return range;
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	int a[] = {1, 7, 7, 8, 8};
	vector<int> range;

	range = sol.searchRange(a, 5, 9);

	cout << range[0] << " " << range[1] << endl;

	return 0;
}

