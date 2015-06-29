class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int pos = -1;
        map<char, int> m;
        for (char c : str)
            ++m[c];
        for (int i = 0; i < str.size(); i++) {
            if (m[str[i]] == 1) {
                pos = i;
                break;
            }
        }
        return pos;
    }
};
