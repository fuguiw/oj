class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;

        if (nums.empty())
            return v;

        int start = 0;
        for (int i = 1; i <= nums.size(); i++) {
            if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
                string s = to_string(nums[start]);
                if (i - 1 != start) {
                    s = s + "->" + to_string(nums[i - 1]);
                }
                v.push_back(s);
                start = i;
            }
        }

        return v;
    }
};
