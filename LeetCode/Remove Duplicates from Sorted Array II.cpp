class Solution {
public:
    int removeDuplicates(int A[], int n) {
		int i, j;

		if (n < 3) 
			return n;

		for (i = j = 0; i < n; i++) {
			if (i >= 2 && A[i] == A[i - 2])
				continue;
			A[j++] = A[i];
			if (i < n - 1 && A[i + 1] == A[i])
				A[j++] = A[i++];
		}

		return j;
    }
};

