class Solution {
public:
    int removeElement(int A[], int n, int elem) {
		int i, j;

		for (i = 0, j = n - 1; i <= j; ) {
			if (A[i] == elem)
				swap(A[i], A[j--]);
			else
				i++;
		}
		return j + 1;
    }
};

