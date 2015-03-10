class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt;

        for (cnt = 0; n; n &= (n - 1))
            ++cnt;

        return cnt;
    }
};
