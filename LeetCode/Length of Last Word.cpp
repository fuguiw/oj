class Solution {
public:
    int lengthOfLastWord(const char *s) {
		int len = 0;
		int i;
		for (i = strlen(s) - 1; i >= 0; i--)
			if (s[i] != ' ')
				break;
		for (; i >= 0; i--, len++)
			if (s[i] == ' ')
				break;
		return len;
    }
};

