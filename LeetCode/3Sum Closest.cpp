#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
		int len;
		int rnt;
		int before, after;
		int tmp;

		len = num.size();
		rnt = num[0] + num[1] + num[2];

		sort(num.begin(), num.end());

		for (int i = 1; i < len - 1; i++) {
			before = 0;
			after = len - 1;
			for ( ; before < i && after > i; ) {
				tmp = num[before] + num[i] + num[after];
				if (fabs(tmp - target) < fabs(rnt - target))
					rnt = tmp;

				if (tmp > target) {
					--after;
				} else {
					++before;
				}
			}
		}

		return rnt;
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	vector<int> num;

	num.push_back(0);
	num.push_back(2);
	num.push_back(1);
	num.push_back(-3);

	cout << sol.threeSumClosest(num, 1) << endl;

	return 0;
}

