#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
		string revision1, revision2;
		istringstream s1(version1);
		istringstream s2(version2);

		while (getline(s1, revision1, '.')) {
			if (!getline(s2, revision2, '.')) {
				if (atoi(revision1.c_str()) != 0)
					return 1;
				else
					continue;
			}

			if (atoi(revision1.c_str()) > atoi(revision2.c_str()))
				return 1;

			if (atoi(revision1.c_str()) < atoi(revision2.c_str()))
				return -1;
		}

		while (getline(s2, revision2, '.'))
			if (atoi(revision2.c_str()) != 0)
				return -1;

		return 0;
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	string a;
	string b;

	while (cin >> a >> b)
		cout << sol.compareVersion(a, b) << endl;

	return 0;
}
