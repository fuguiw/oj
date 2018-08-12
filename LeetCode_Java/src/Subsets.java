import java.util.LinkedList;
import java.util.List;

public class Subsets {

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> subsets = new LinkedList<>();
        subsets.add(new LinkedList<Integer>());

        for (int i = 0; i < nums.length; i++) {
            int size = subsets.size();
            for (int j = 0; j < size; j++) {
                List<Integer> subset = subsets.get(j);
                List<Integer> newSubset = new LinkedList<>(subset);
                newSubset.add(nums[i]);
                subsets.add(newSubset);
            }
        }

        return subsets;
    }
}

