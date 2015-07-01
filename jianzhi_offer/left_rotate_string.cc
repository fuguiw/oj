class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.size();
        if (len == 0)
            return str;
        n %= len;
        string ret = str.substr(n);
        ret += str.substr(0, n);
        return ret;
    }
};
