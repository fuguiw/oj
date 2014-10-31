#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		vector<int> nums;
		vector<int>::iterator it;

		it = digits.end() - 1;
		*it += 1;
		for ( ; it > digits.begin(); it--) {
			if (*it <= 9) {
				break;
			}
			*it = 0;
			*(it - 1) += 1;
		}
		
		for (it = digits.begin(); it < digits.end(); it++) {
			if (*it == 10) {
				nums.push_back(1);
				nums.push_back(0);
			} else {
				nums.push_back(*it);
			}
		}
		return nums;
    }
};

int main()
{
	Solution sol;
	vector<int> v;
	v.push_back(2);
	v = sol.plusOne(v);
	cout << v[0] << endl;
}
