#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
		int len = s.size();
		int i, start = -1, end = -1;

		for (i = 0; i < len; i++)
			if (!isspace(s[i]))
				break;
		s.erase(0, i);

		len = s.size();
		for (i = len - 1; i >= 0; i--)
			if (!isspace(s[i]))
				break;
		s.erase(i + 1, len - 1 - i);

		len = s.size();
		for (i = 0; i < len / 2; i++)
			swap(s[i], s[len - 1 - i]);

		s.push_back(' ');
		for (i = 0; i <= len; i++) {
			if (start == -1 && !isspace(s[i])) {
				if (end != -1) {
					s.erase(end + 2, i - 2 - end);
					len -= (i - 2 - end);
					i = end + 2;
				}
				start = i;
			}
			if (isspace(s[i]) && start != -1) {
				for (int j = start; j < (start + i) / 2; j++)
					swap(s[j], s[i - 1 - j + start]);
				start = -1;
				end = i - 1;
			}
		}
		s.pop_back();
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	string s("   a   b  c d   e  ");
	sol.reverseWords(s);
	cout << s << endl;

	return 0;
}
