class Solution {
public:
    string getHint(string secret, string guess) {
        int len = secret.size();
        int a_cnt = 0;
        vector<int> s_cnt(10, 0);
        vector<int> g_cnt(10, 0);
        for (int i = 0; i < len; ++i) {
            int x = secret[i] - "0";
            int y = guess[i] - "0";
            if (x == y)
                ++a_cnt;
            ++s_cnt[x];
            ++g_cnt[y];
        }

        int b_cnt = 0;
        for (int i = 0; i < 10; ++i)
            b_cnt += min(s_cnt[i], g_cnt[y]);

        b_cnt -= a_cnt;
        return to_string(a_cnt) + "A" + to_string(b_cnt) + "B";
    }
};
