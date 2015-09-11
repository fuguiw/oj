class Solution {
public:
    int numSquares(int n) {
        vector<int> v(n + 1, 0);
        for (int i = 1; i * i <= n; ++i) {
            int tmp = i * i;
            for (int j = tmp; j <= n; ++j) {
                if (v[j] == 0)
                    v[j] = v[j - tmp] + 1;
                else
                    v[j] = min(v[j], v[j - tmp] + 1);
            }
        }
        return v[n];
    }
};
