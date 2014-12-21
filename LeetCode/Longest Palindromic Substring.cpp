#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		int len = s.size();
		int longest = 0;
		string ret = s;
		int i, j;

		for (i = 0; i < len - 1; i++) {
			if (min(i, len - i) * 2 + 2 < longest) continue;

			for (j = 1; j <= i && i + j < len; j++) {
				if (s[i - j] != s[i + j]) {
					break;
				}
			}
			if (longest < j * 2 - 1) {
				longest = j * 2 - 1;
				ret = s.substr(i - j + 1, longest); 
			}

			if (s[i + 1] == s[i]) {
				for (j = 1; j <= i && i + 1 + j < len; j++) {
					if (s[i - j] != s[i + 1 + j]) {
						break;
					}
				}
				if (longest < j * 2) {
					longest = j * 2;
					ret = s.substr(i - j + 1, longest); 
				}
			}
		}

		return ret;
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	string s;

	while (cin >> s)
		cout << sol.longestPalindrome(s) << endl;

	return 0;
}
