public class MaxProfit122 {
    public int maxProfit(int[] prices) {
        int[] profit = new int[prices.length];
        int result = 0;

        for (int i = 0; i < prices.length; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (prices[i] > prices[j]) {
                    profit[i] = Math.max(profit[i], prices[i] - prices[j] + (j > 0 ? profit[j - 1] : 0));
                }
                if (i > 0) {
                    profit[i] = Math.max(profit[i], profit[i - 1]);
                }
            }

            result = Math.max(result, profit[i]);
        }

        return result;
    }
}
