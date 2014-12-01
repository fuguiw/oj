#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		int len;
		int left, right;
		int tmp;
		vector<vector<int> > ret;

		len = num.size();

		sort(num.begin(), num.end());

		for (int i = 0; i < len - 2; ++i) {
			if (i > 0 && num[i] == num[i - 1]) 
				continue;

			left = i + 1;
			right = len - 1;
			for (; left < right; ) {
				if (left > i + 1 && num[left] == num[left - 1]) {
					left++;
					continue;
				}

				if (right < len - 1 && num[right] == num[right + 1]) {
					right--;
					continue;
				}

				tmp = num[left] + num[i] + num[right];
				if (tmp == 0) {
					vector<int> three;
					three.push_back(num[i]);
					three.push_back(num[left]);
					three.push_back(num[right]);
					ret.push_back(three);
				}

				tmp > 0 ? --right : ++left;
			}
		}

		return ret;
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	vector<vector<int> > v;
	int n[] = {12,5,-12,4,-11,11,2,7,2,-5,-14,-3,-3,3,2,-10,9,-15,2,14,-3,-15,-3,-14,-1,-7,11,-4,-11,12,-15,-14,2,10,-2,-1,6,7,13,-15,-13,6,-10,-9,-14,7,-12,3,-1,5,2,11,6,14,12,-10,14,0,-7,11,-10,-7,4,-1,-12,-13,13,1,9,3,1,3,-5,6,9,-4,-2,5,14,12,-5,-6,1,8,-15,-10,5,-15,-2,5,3,3,13,-8,-13,8,-5,8,-6,11,-12,3,0,-2,-6,-14,2,0,6,1,-11,9,2,-3,-6,3,3,-15,-5,-14,5,13,-4,-4,-10,-10,11};
	vector<int> num(n, n + sizeof(n) / sizeof(int));

	/* num.push_back(-1); */
	/* num.push_back(1); */
	/* num.push_back(0); */

	v = sol.threeSum(num);
	cout << v.size() << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cout << v[i][j] << endl;

	return 0;
}
