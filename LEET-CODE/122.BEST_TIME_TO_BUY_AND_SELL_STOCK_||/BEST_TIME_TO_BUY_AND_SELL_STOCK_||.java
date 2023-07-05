class Solution {
    public int maxProfit(int[] prices) {
        int currsm = Integer.MAX_VALUE;  // Variable to track the current smallest price
        int profit = 0;  // Variable to store the total profit
        
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] <= currsm) {
                currsm = prices[i];  // Update the current smallest price
            } else if (currsm != Integer.MAX_VALUE) {
                // If the current price is greater than the smallest price and a valid smallest price exists
                // Calculate the profit by selling at the current price and buying at the smallest price
                profit = profit + prices[i] - currsm;
            }
        }
        
        return profit;  // Return the total profit
    }
}
