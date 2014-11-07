public:
    string convert(string s, int nRows) {
		if (nRows == 1)
			return s;

		string strs[nRows];
		string ret;
		int next = 1;
		int curr = 0;
		int len = s.size();
		
		for (int i = 0; i < len; i++) {
			strs[curr].push_back(s[i]);
			if (curr == nRows - 1)
				next = -1;
			if (curr == 0)
				next = 1;
			curr += next;
		}

		for (int i = 0; i < nRows; i++)
			ret += strs[i];

		return ret;
    }
};

