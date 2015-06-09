#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();

        if (len1 == 0 && len2 == 0)
            return true;

        if (len1 == 1 && len2 == 1 && s1 == s2)
            return true;

        for (int i = 1; i < len1; i++) {
            string str1 = s1.substr(0, i);
            sort(str1.begin(), str1.end());

            string str2 = s2.substr(0, i);
            sort(str2.begin(), str2.end());
            if (str1 == str2) {
                if (isScramble(s1.substr(0, i), s2.substr(0, i)) 
                        && isScramble(s1.substr(i, len1 - i), s2.substr(i, len2 - i)))
                    return true;
            }

            str2 = s2.substr(len2 - i, i);
            sort(str2.begin(), str2.end());
            if (str1 == str2) {
                if (isScramble(s1.substr(0, i), s2.substr(len2 - i, i)) 
                        && isScramble(s1.substr(i, len1 - i), s2.substr(0, len2 - i)))
                    return true;
            }
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s1, s2;
    while (cin >> s1 >> s2) {
        cout << sol.isScramble(s1, s2) << endl;
    }
    return 0;
}
