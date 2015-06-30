class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        auto begin = lower_bound(data.begin(), data.end(), k);
        auto end = upper_bound(data.begin(), data.end(), k);

        return end - begin;
    }
};
