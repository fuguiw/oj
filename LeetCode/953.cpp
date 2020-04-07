#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> m;
        for (int i = 0; i < order.size(); i++) {
            m[order[i]] = i;
        }

        auto convert = [&m](string a) -> string {
            string b;
            for (int i = 0; i < a.size(); i++) {
                b += m[a[i]];
            }
            return b;
        };

        for (int i = 1; i < words.size(); i++) {
            if (convert(words[i - 1]) > convert(words[i])) {
                return false;
            }
        }
        return true;
    }
};