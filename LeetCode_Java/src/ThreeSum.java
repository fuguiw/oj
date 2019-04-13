import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class ThreeSum {
    private void twoSum(int[] nums, int begin, List<List<Integer>> results) {
        int end = nums.length - 1;
        int target = -nums[begin - 1];
        while (begin < end) {
            if (nums[begin] + nums[end] == target) {
                List<Integer> result = new LinkedList<>();
                result.add(-target);
                result.add(nums[begin]);
                result.add(nums[end]);
                results.add(result);
                do {
                    begin++;
                } while (begin < end && nums[begin] == nums[begin - 1]);
            } else if (nums[begin] + nums[end] > target) {
                end--;
            } else {
                begin++;
            }
        }
    }

    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);

        List<List<Integer>> results = new LinkedList<>();
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            List<Integer> result = new LinkedList<>();
            result.add(nums[i]);
            twoSum(nums, i + 1, results);
        }

        return results;
    }
}
