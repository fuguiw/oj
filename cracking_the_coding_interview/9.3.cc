class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n) {
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] < mid)
                left = mid + 1;
            else if (A[mid] > mid)
                right = mid - 1;
            else
                return true;
        }
        return false;
    }
};
