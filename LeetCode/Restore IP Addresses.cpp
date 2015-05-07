#include <iostream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    void restoreIpAddresses(vector<string> &v, const string &s, string ip, int i, int cnt) {
        string str;
        if (i < s.size() && cnt == 4) {
            if (s.size() - i > 3)
                return ;
            str = s.substr(i);
            if ((str.size() == 1 && stoi(str) == 0) || (stoi(str) > 0 && stoi(str) <= 255 && str[0] != '0')) {
                ip = ip + str;
                v.push_back(ip);
            }

            return ;
        }

        for (; i < s.size(); i++) {
            str += s[i];

            if ((str.size() > 1 && str[0] == '0') || stoi(str) > 255)
                break;

            if (stoi(str) >= 0)
                restoreIpAddresses(v, s, ip + str + ".", i + 1, cnt + 1);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;

        restoreIpAddresses(v, s, string(), 0, 1);

        return v;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s("00000");
    vector<string> v = sol.restoreIpAddresses(s);

    for (auto s : v)
        cout << s << endl;

    return 0;
}
