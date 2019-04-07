public class MajorityElement {
    public int majorityElement(int[] nums) {
        int element = nums[0];
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                element = num;
                count = 1;
            } else {
                if (element != num) {
                    count--;
                } else {
                    count++;
                }
            }
        }

        return element;
    }
}
