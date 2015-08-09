class MinimalBST {
    int buildMinimalBST(int left, int right) {
        if (left == right)
            return 1;
        if (left > right)
            return 0;
        int mid = (left + right) / 2;
        return max(buildMinimalBST(left, mid - 1), buildMinimalBST(mid + 1, right)) + 1;
    }

public:
    int buildMinimalBST(vector<int> vals) {
        return buildMinimalBST(0, vals.size() - 1);
    }
};
