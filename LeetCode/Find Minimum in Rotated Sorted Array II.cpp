#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	int findMin(vector<int> &num, int start, int end) {
		int mid;

		if (num[start] < num[end])
			return num[start];

		while (start < end) {
			mid = (start + end) / 2;
			if (num[mid] < num[start]) {
				end = mid;
			} else if (num[mid] > num[end]) {
				start = mid + 1;
			} else {
				return min(findMin(num, start, mid - 1), findMin(num, mid + 1, end));
			}
		}

		return num[start];
	}

public:
    int findMin(vector<int> &num) {
		int len = num.size();

		if (!len)
			return 0;

		return findMin(num, 0, len - 1);
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	vector<int> v;

	v.push_back(3);
	v.push_back(3);
	v.push_back(2);
	v.push_back(3);

	cout << sol.findMin(v) << endl;
	return 0;
}
