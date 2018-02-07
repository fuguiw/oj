import java.util.ArrayList;
import java.util.List;

public class RangeSumQuery {

    private List<Integer> rangeSum;
    int[] nums;

    public NumArray(int[] nums) {
        rangeSum = new ArrayList<>();
        this.nums = nums;

        for (int i = 0; i < nums.length; i++) {
            rangeSum.add(nums[i] + (i > 0 ? rangeSum.get(i - 1) : 0));
        }
    }

    public int sumRange(int i, int j) {
        return rangeSum.get(j) - rangeSum.get(i) + nums[i];
    }
}


