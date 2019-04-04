import java.util.Arrays;

public class ThreeSumClosest {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);

        int sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.length - 2; i++) {
            int left = i + 1;
            int right = nums.length - 1;
            int subTarget = target - nums[i];

            while (left < right) {
                int subSum = nums[left] + nums[right];
                if (Math.abs(target - sum) > Math.abs(subTarget - subSum)) {
                    sum = nums[i] + subSum;
                }
                if (subSum > subTarget) {
                    right--;
                } else if (subSum < subTarget) {
                    left++;
                } else {
                    return target;
                }
            }
        }

        return sum;
    }
}
