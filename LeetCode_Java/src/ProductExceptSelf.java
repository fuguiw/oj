import java.util.Arrays;

class ProductExceptSelf {
    public int[] productExceptSelf(int[] nums) {
        int[] leftProduct = new int[nums.length];
        int[] rightProduct = new int[nums.length];

        Arrays.fill(leftProduct, 1);
        Arrays.fill(rightProduct, 1);

        for (int i = 1; i < nums.length; i++) {
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
        }
        for (int i = nums.length - 2; i >= 0; i--) {
            rightProduct[i] = rightProduct[i + 1] * nums[i + 1];
        }

        int[] product = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            product[i] = leftProduct[i] * rightProduct[i];
        }

        return product;
    }
}