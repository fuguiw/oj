import java.lang.reflect.Array;
import java.util.*;

public class Permute {
    List<List<Integer>> permutes;

    private void permute(int[] nums, int index) {
        if (index == nums.length - 1) {
            List<Integer> l = new ArrayList<>(nums.length);
            for (Integer num : nums) {
                l.add(num);
            }
            permutes.add(l);
        }

        for (int i = index; i < nums.length; i++) {
            int tmp = nums[index];
            nums[index] = nums[i];
            nums[i] = tmp;

            permute(nums, index + 1);

            tmp = nums[index];
            nums[index] = nums[i];
            nums[i] = tmp;
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        permutes = new ArrayList<>();
        permute(nums, 0);
        return permutes;
    }
}
