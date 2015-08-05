class Robot {
public:
    int countWays(int x, int y) {
        vector<vector<int>> count(x, vector<int>(y, 0));
        count[0][0] = 1;
        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < y; ++j)
            {
                if (i > 0)
                    count[i][j] += count[i - 1][j];
                if (j > 0)
                    count[i][j] += count[i][j - 1];
            }
        }
        return count[x - 1][y - 1];
    }
};
