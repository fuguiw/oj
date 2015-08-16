#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class SortString {
public:
    vector<string> sortStrings(vector<string> str, int n) {
        map<string, vector<string>> hash;
        for (string s : str)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            if (hash.find(tmp) == hash.end())
            {
                hash.insert(make_pair(tmp, vector<string>()));
            }
            hash[tmp].push_back(s);
        }

        vector<string> rnt;
        for (auto p : hash)
        {
            sort(p.second.begin(), p.second.end());
            rnt.push_back(p.second[0]);
        }
        sort(rnt.begin(), rnt.end());

        return rnt;
    }
};

int main(int argc, char *argv[])
{
    SortString sol;
    vector<string> v{"acb", "bca", "abc", "cba"};
    v = sol.sortStrings(v, 4);
    for (auto s : v)
        cout << s << endl;
    return 0;
}
