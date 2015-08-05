class Robot {
    static const int kMod = 1000000007;
public:
    int countWays(vector<vector<int> > map, int x, int y) {
        vector<vector<int>> count(x, vector<int>(y, 0));
        if (map[0][0] == 1)
            count[0][0] = 1;
        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < y; ++j)
            {
                if (map[i][j] != 1)
                    continue;
                if (i > 0)
                    count[i][j] = (count[i][j] + count[i - 1][j]) % kMod;
                if (j > 0)
                    count[i][j] = (count[i][j] + count[i][j - 1]) % kMod;
            }
        }
        return count[x - 1][y - 1];
    }
};

