public class MaxArea {
    public int maxArea(int[] height) {
        int result = 0;
        for (int i = 0; i < height.length; i++) {
            for (int j = height.length - 1; j > i; j--) {
                int area = (j - i) * Math.min(height[i], height[j]);
                result = Math.max(result, area);
                if (height[j] > height[i] || area < result) {
                    break;
                }
            }
        }
        return result;
    }
}
