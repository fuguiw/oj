class Solution {
public:
    int findPeakElement(const vector<int> &num) {
		int start, end, mid;
		long long left, right;
		int len;

		len = num.size();
		start = 0;
		end = len - 1;

		while (start <= end) {
			mid = (start + end) / 2;
			left = mid == 0 ? LLONG_MIN : num[mid - 1];
			right = mid == len - 1 ? LLONG_MIN : num[mid + 1];

			if (num[mid] > left && num[mid] > right)
				return mid;

			if (left < right)
				start = mid + 1;
			else
				end = mid - 1;
		}

		return -1;
    }
};

