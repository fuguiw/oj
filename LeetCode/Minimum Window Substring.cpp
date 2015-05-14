#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() == 0)
            return string();

        int tm[256] = {};
        for (auto c : t)
            tm[static_cast<int>(c)]++;

        string min_str;
        int min_len = INT_MAX;
        int sm[256] = {};
        int cnt = 0;

        for (int start = 0, end = 0; end < static_cast<int>(s.size()); end++) {
            int c = s[end];
            if (++sm[c] <= tm[c])
                cnt++;

            if (cnt == t.size()) {
                for (; start <= end; start++) {
                    c = s[start];
                    if (sm[c] > tm[c]) sm[c]--;
                    else  break; 
                }
                
                if (min_len > end - start + 1) {
                    min_len = end - start + 1;
                    min_str = s.substr(start, min_len);
                }
            }
        }
           
        return min_str;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s("ADOBECODEBANC");
    string t("ABC");

    cout << sol.minWindow(s, t) << endl;

    return 0;
}
