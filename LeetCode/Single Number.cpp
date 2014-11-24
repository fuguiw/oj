class Solution {
public:
    int singleNumber(int A[], int n) {
		int rnt = 0;

		for (int i = 0; i < n; i++)
			rnt ^= A[i];

		return rnt;
    }
};
