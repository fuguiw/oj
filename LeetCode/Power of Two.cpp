class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n && n > INT_MIN)
            return !(n & (n - 1));
        return false;
    }
};
