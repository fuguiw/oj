#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int len = s.size();
		int m[444] = {0};
		int start = 0;
		int rnt = 0;
		int pre = 0;

		for (int i = 0; i < len; ++i) {
			if (!m[(int)s[i]]) {
				m[(int)s[i]] = 1;
				++pre;
				rnt = max(rnt, pre);
				continue;
			}

			for ( ;start < i; start++) {
				m[(int)s[start]] = 0;
				if (!m[(int)s[i]])
					break;
			}

			++start;

			m[(int)s[i]] = 1;
			pre = i - start + 1;
			rnt = max(rnt, pre);
		}

		return rnt;
    }
};

int main()
{
	string s;
	Solution sol;

	while (cin >> s)
		cout << sol.lengthOfLongestSubstring(s) << endl;

	return 0;
}
