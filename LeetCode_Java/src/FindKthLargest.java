import java.lang.reflect.Array;
import java.util.Arrays;

public class FindKthLargest {
    private int partition(int[] nums, int begin, int end) {
        int part = begin - 1;
        for (int i = begin; i < end; i++) {
            if (nums[i] > nums[end - 1]) {
                int tmp = nums[i];
                nums[i] = nums[++part];
                nums[part] = tmp;
            }
        }

        int tmp = nums[++part];
        nums[part] = nums[end - 1];
        nums[end - 1] = tmp;

        return part;
    }

    private int findKthLargest(int[] nums, int begin, int end, int k) {
        int index = partition(nums, begin, end);
        System.out.printf("%d, %d, %d\n", begin, end, k);
        System.out.println(Arrays.toString(nums));
        System.out.println(index);
        if (index + 1 - begin == k) {
            return nums[index];
        } else if (index + 1 < k) {
            return findKthLargest(nums, index + 1, end, k - index - 1);
        } else {
            return findKthLargest(nums, begin, index, k);
        }
    }

    public int findKthLargest(int[] nums, int k) {
        return findKthLargest(nums, 0, nums.length, k);
    }
}
