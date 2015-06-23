#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string str) {
        int len = str.size();
        int space_count = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] == ' ')
                ++space_count;
        }

        len += space_count * 2;
        string ret(len, ' ');
        int i = len - 1;
        int j = str.size() - 1;
        while (i >= 0) {
            if (str[j] == ' ') {
                ret[i--] = '0';
                ret[i--] = '2';
                ret[i--] = '%';
                --j;
            } else {
                ret[i--] = str[j--];
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s("hello world");
    cout << sol.replaceSpace(s) << endl;
    return 0;
}
