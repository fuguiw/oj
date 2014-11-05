class Solution {
public:
    int removeDuplicates(int A[], int n) {
		int i, j;
		
		if (!n) return 0;
		for (i = j = 0; i < n; i++) {
			if (i == 0) continue;
			if (A[i] == A[i - 1]) continue;
			A[++j] = A[i];
		}
		return j + 1;
    }
};

