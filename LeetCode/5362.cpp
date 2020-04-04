#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) {
            return false;
        }
        if (k == s.size()) {
            return true;
        }

        map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }

        int odd = 0;
        for (auto itr = m.begin(); itr != m.end(); itr++) {
            if (itr->second % 2) {
                odd++;
            }
        }

        return odd <= k;
    }
};