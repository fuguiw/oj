#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
		int left, right;
		int rnt;
		int len;

		len = height.size();
		left = 0;
		right = len - 1;
		rnt = 0;

		while (left < right) {
			rnt = max(rnt, min(height[left], height[right]) * (right - left));
			height[left] > height[right] ? --right : ++left;
		}

		return rnt;
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	vector<int> h;

	h.push_back(1);
	h.push_back(2);
	h.push_back(3);
	h.push_back(4);

	cout << sol.maxArea(h) << endl;

	return 0;
}

