class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int n, m;
		int left, right, mid;
		int tmp;

		if (!(n = matrix.size()))
			return false;
		m = matrix[0].size();

		left = 0;
		right = n * m - 1;

		while (left <= right) {
			mid = (left + right) / 2;
			tmp = matrix[mid / m][mid % m];

			if (tmp == target)
				return true;

			if (tmp > target) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}

		return false;
    }
};
