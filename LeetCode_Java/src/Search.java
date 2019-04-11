public class Search {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
//            System.out.printf("%d, %d, %d\n", left, right, mid);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                if (target > nums[right] && nums[mid] > nums[right] || target < nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            } else {
                if (target < nums[left] && nums[mid] < nums[left] || target >= nums[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
}
