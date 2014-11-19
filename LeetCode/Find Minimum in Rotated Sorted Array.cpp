#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
		int len = num.size();
		int start = 0;
		int end = len - 1;
		int mid;

		if (!len)
			return 0;

		if (num[start] <= num[end])
			return num[start];

		while (start < end) {
			mid = (start + end) / 2;
			if (num[mid] < num[len - 1])
				end = mid;
			else 
				start = mid + 1;
		}
		return num[start];
    }
};

int main()
{
	vector<int> num;
	Solution sol;

	num.push_back(3);
	num.push_back(1);

	cout << sol.findMin(num) << endl;
	return 0;
}
