public class FindMin {
    public int findMin(int[] nums) {
        int begin = 0;
        int end = nums.length - 1;

        while (begin < end) {
            int mid = (begin + end) / 2;
            if (nums[mid] >= nums[0]) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return Math.min(nums[0], nums[begin]);
    }
}
