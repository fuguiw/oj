#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		int carry = 0;
		int la = a.size();
		int lb = b.size();
		int lc = max(la, lb);
		int ta, tb;
		string sum(lc, '0');

		for (; la > 0 && lb > 0;) {
			ta = a[--la] - '0';
			tb = b[--lb] - '0';
			sum[--lc] = ta ^ tb ^ carry + '0';
			carry = (ta + tb + carry) / 2;
		}
		for (;la > 0;) {
			ta = a[--la] - '0';
			sum[--lc] = ta ^ carry + '0';
			carry = ta & carry;
		} 
		for (;lb > 0;) {
			tb = b[--lb] - '0';
			sum[--lc] = tb ^ carry + '0';
			carry = tb & carry;
		}
		if (carry) sum.insert(sum.begin(), '1');
		return sum;
    }
};

int main()
{
	Solution sol;
	string a = "11111";
	string b = "1";
	cout << sol.addBinary(a, b) << endl;
	return 0;
}
