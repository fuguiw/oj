#include <iostream>
using namespace std;

class Solution {
private:
	void getNext(char *needle, int next[])
	{
		int len = strlen(needle);
		int k = -1;
		int j = 0;

		next[0] = -1;
		while (j < len - 1) {
			if (k == -1 || needle[k] == needle[j]) {
				k++;
				j++;
				next[j] = k;
			} else {
				k = next[k];
			}
		}
	}

	int kmp(char *haystack, char *needle)
	{
		int len1 = strlen(haystack);
		int len2 = strlen(needle);
		int i, j;
		int next[len2];

		getNext(needle, next);
		for (i = j = 0; i < len1 && j < len2; ) {
			if (j == -1 || haystack[i] == needle[j]) {
				i++;
				j++;
			} else {
				j = next[j];
			}
		}
		if (j == len2)
			return i - j;
		else
			return -1;
	}

public:
    int strStr(char *haystack, char *needle) {
		return kmp(haystack, needle);
    }
};

int main()
{
	char a[100], b[100];
	Solution sol;
	while (cin >> a >> b) 
		cout << sol.strStr(a, b) << endl;
	return 0;
}

