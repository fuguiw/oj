class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());
        string::iterator begin, end;
        for (begin = end = str.begin(); begin != str.end(); ) {
            if (end == str.end() || isspace(*end)) {
                reverse(begin, end);
                if (end != str.end())
                    ++end;
                begin = end;
            } else {
                ++end;
            }
        }
        return str;
    }
};
