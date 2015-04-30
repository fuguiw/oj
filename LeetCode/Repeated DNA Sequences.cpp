#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
    void clear_oldest(int &n) { n &= ~(3 << 20); }
    void add(int &n, char c) {
        if (c == 'A') n = n << 2 | 0;
        if (c == 'C') n = n << 2 | 1;
        if (c == 'G') n = n << 2 | 2;
        if (c == 'T') n = n << 2 | 3;
    }

public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> v;
        map<int, int> m;
        int key = 0;
        int len = s.size();

        for (int i = 0; i < len; i++) {
            add(key, s[i]);
            if (i >= 9) {
                clear_oldest(key);
                ++m[key];
                if (m[key] == 2)
                    v.push_back(s.substr(i - 9, 10));
            }
        }

        return v;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<string> v;

    v = sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");

    for (auto &s : v)
        cout << s << endl;

    return 0;
}
