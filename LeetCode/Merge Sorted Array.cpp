class Solution {
public:
    void merge(int A[], int m, int B[], int n)
	{
		int i, j, k;
		
		i = m - 1;
		j = n - 1;
		k = n + m - 1;

		for (; k >= 0; ) {
			if (i < 0) {A[k--] = B[j--]; continue;}
			if (j < 0) {A[k--] = A[i--]; continue;}
			if (A[i] >= B[j]) A[k--] = A[i--];
			else A[k--] = B[j--];
		}
    }
};
