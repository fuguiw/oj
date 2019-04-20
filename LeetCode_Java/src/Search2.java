public class Search2 {
    public boolean search(int[] nums, int target) {
        if (nums == null) {
            return false;
        }

        int left = 0;
        int right = nums.length;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > target) {
                if (target >= nums[left]) {
                    right--;
                } else {
                    left++;
                }
            } else {
                if (target <= nums[right]) {
                    left++;
                } else {
                    right--;
                }
            }

        }

        return false;
    }
}
