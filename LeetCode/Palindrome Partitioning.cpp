#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<string> > ret;
    vector<string> v;
    string str;
    int len;

    int isP(int i, int j) {
        while (i < j) {
            if (str[i++] != str[j--])
                return 0;
        }

        return 1;
    }
    
    void partition(int i) {
        for (int j = i; j < len; j++) {
            if (isP(i, j)) {
                v.push_back(str.substr(i, j - i + 1));
                if (j == len - 1) {
                    ret.push_back(v);
                } else {
                    partition(j + 1);
                }
                v.pop_back();
            }
        }
    }

public:
    vector<vector<string> > partition(string s) {
        ret.clear();
        v.clear();
        str = s;
        len = str.size();

        partition(0);

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s;
    vector<vector<string> > vv;
    vector<string> v;

    while (cin >> s) {
        vv = sol.partition(s);

        for (int i = 0; i < vv.size(); i++)
            for (int j = 0; j < vv[i].size(); j++)
                cout << vv[i][j] << endl;
    }
    return 0;
}
