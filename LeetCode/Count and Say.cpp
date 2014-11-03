#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
	string sayNext(string s) {
		string next;
		int cnt;
		char pre;
		int len = s.size();

		cnt = 1;
		pre = s[0];

		for (int i = 1; i < len; i++) {
			if (s[i] != pre) {
				next.push_back(cnt + '0');
				next.push_back(pre);
				pre = s[i];
				cnt = 1;
			} else {
				cnt++;
			}
		}
		next.push_back(cnt + '0');
		next.push_back(pre);
		return next;
	}

public:
    string countAndSay(int n) {
		string s("1");

		while (--n)
			s = sayNext(s);

		return s;
    }
};

int main()
{
	Solution sol;
	int n;
	while (cin >> n)
		cout << sol.countAndSay(n) << endl;
	return 0;
}

