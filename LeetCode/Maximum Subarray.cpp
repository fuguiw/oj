class Solution {
public:
    int maxSubArray(int A[], int n) {
		int rnt = INT_MIN;
		int sum = 0;

		for (int i = 0; i < n; i++) {
			if (sum > 0) {
				sum += A[i];
			} else {
				sum = A[i];
			}
			rnt = max(rnt, sum);
		}

		return rnt;
    }
};

