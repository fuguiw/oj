#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0)
			return false;
		int bits = log10(x) + 1;
		while (bits > 1) {
			int tmp = pow(10, bits - 1);
			if (x % 10 != x / tmp)
				return false;
			x -= x / tmp * tmp;
			x /= 10;
			bits -= 2;
		}
		return true;
    }
};

int main()
{
	Solution sol;
	int x;
	while (cin >> x)
		cout << sol.isPalindrome(x) << endl;
	return 0;
}

