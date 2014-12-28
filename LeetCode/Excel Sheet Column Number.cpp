class Solution {
public:
    int titleToNumber(string s) {
        int rnt = 0;
        int len = s.size();

        for (int i = 0; i < len; i++) {
            rnt = rnt * 26 + (s[i] - 'A') + 1;
        }

        return rnt;
    }
};

