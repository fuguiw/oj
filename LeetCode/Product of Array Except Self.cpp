class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product(nums.size(), 1);

        int tmp = 1;
        for (int i = 1; i < nums.size(); i++) {
            tmp *= nums[i - 1];
            product[i] *= tmp;
        }

        tmp = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            tmp *= nums[i + 1];
            product[i] *= tmp;
        }

        return product;
    }
};
