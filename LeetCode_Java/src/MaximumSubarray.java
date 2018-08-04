public class MaximumSubarray {
    public int maxSubArray(int[] nums) {
        int[] sum = new int[nums.length];
        int maxSum = nums[0];
        sum[0] = nums[0];

        for (int i = 1; i < nums.length; i++) {
            sum[i] = nums[i] + (sum[i - 1] > 0 ? sum[i - 1] : 0);
            maxSum = Math.max(maxSum, sum[i]);
        }

        return maxSum;
    }
}
