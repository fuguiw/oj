class Solution {
public:
    int searchInsert(int A[], int n, int target) {
		int left, right, mid;

		left = 0;
		right = n - 1;

		while (left <= right) {
			mid = (left + right) / 2;
			if (A[mid] == target)
				return mid;

			if (A[mid] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}

		return left;
    }
};

