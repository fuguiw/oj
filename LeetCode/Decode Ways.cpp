#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
		int len = s.size();
		int num[len + 1];
		int tmp;

		if (!len || s[0] == '0')
			return 0;

		memset(num, 0, sizeof(num));
		num[0] = 1;
		for (int i = 1; i <= len; i++) {
			tmp = s[i - 1] - '0';
			if (tmp)
				num[i] = num[i - 1];
			if (i > 1) {
				tmp += (s[i - 2] - '0') * 10;
				if (!tmp)
					return 0;
				if (tmp >= 10 && tmp <= 26)
					num[i] += num[i - 2];
			}
		}
		return num[len];
    }
};

int main()
{
	Solution sol;
	string s;
	while (cin >> s)
		cout << sol.numDecodings(s) << endl;
	return 0;
}
