class Solution {
public:
    bool match(char* str, char* pattern)
    {
        int lens = strlen(str);
        int lenp = strlen(pattern);

        vector<vector<bool>> match(lens + 1, vector<bool>(lenp + 1, false));
        match[0][0] = true;

        for (int i = 2; i <= lenp; i+=2)
            if (match[0][i - 2] && pattern[i - 1] == '*')
                match[0][i] = true;
            else
                break;

        for (int i = 1; i <= lens; i++) {
            for (int j = 1; j <= lenp; j++) {
                if (pattern[j - 1] == '*') {
                    match[i][j] = match[i][j - 2]
                        || (match[i - 1][j] && (str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.'));
                } else {
                    match[i][j] = match[i - 1][j - 1]
                        && (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.');
                }
            }
        }

        return match[lens][lenp];
    }
};
