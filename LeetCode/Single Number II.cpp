class Solution {
public:
    int singleNumber(int A[], int n) {
		int c1, c2, c3, t;
		c1 = c2 = c3 = 0;

		for (int i = 0; i < n; i++) {
			t = c1;
			c1 = t ^ A[i];
			c2 |= t & A[i];
			c3 = c1 & c2;
			c1 &= ~c3;
			c2 &= ~c3;
		}

		return c1;
    }
};

