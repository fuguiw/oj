#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
		int len = s.size();
		int rnt = 0;
		int longest[len];
		stack<int> st;

		for (int i = 0; i < len; i++) {
			longest[i] = 0;

			if (s[i] == '(') {
				st.push(i);
				continue;
			}

			if (!st.empty()) {
				int tmp = st.top();
				st.pop();

				longest[i] = (tmp == 0 ? 0 : longest[tmp - 1]) + (i - tmp + 1);
			}

			rnt = max(rnt, longest[i]);
		}

		return rnt;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	string s;

	while (cin >> s)
		cout << sol.longestValidParentheses(s) << endl;

	return 0;
}
