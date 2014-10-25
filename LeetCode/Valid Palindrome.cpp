#include <string>
#include <iostream>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
		for (int i = 0, j = s.size() - 1; i < j;) {
			if (!isalpha(s[i]) && !isdigit(s[i])) {i++;continue;}
			if (!isalpha(s[j]) && !isdigit(s[j])) {j--;continue;}
			if (tolower(s[i]) != tolower(s[j])) return false;
			i++;
			j--;
		}
		return true;
    }
};

int main()
{
	Solution sol;
	string s;

	while (getline(cin, s)) {
		cout << sol.isPalindrome(s) << endl;
	}
	return 0;
}

