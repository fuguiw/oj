class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_numbers = {1};
        int i2, i3, i5;
        for (i2 = i3 = i5 = 0; i2 < n;) {
            int n2 = ugly_numbers[i2] * 2;
            int n3 = ugly_numbers[i3] * 3;
            int n5 = ugly_numbers[i5] * 5;
            int next = min(n2, min(n3, n5));
            if (next == n2) ++i2;
            if (next == n3) ++i3;
            if (next == n5) ++i5;
            ugly_numbers.push_back(next);
        }
        return ugly_numbers[n - 1];
    }
};

