/**
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 * 
 *我的思路：峰谷法，注意考虑倒数第二天买入的情况
 */
class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;
        int buyDay = -1;
        //state为true寻找买入股票的最佳时间，state为false寻找卖出股票的最佳时间
        boolean state = true;
        int i = 0;
        for (; i < prices.length - 1; i++) {
            if (state) {
                if (prices[i] < prices[i + 1]) {
                    buyDay = i;
                    state = false;
                }
            } else {
                if (prices[i] > prices[i + 1]) {
                    profit += prices[i] - prices[buyDay];
                    state = true;
                }
            }
        }
        //考虑倒数第二天买入的情况
        if (!state) {
            profit += prices[i] - prices[buyDay];
        }
        return profit;
    }
}

/**
 * 较优解法
 */
class Solution {
    public int maxProfit(int[] prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
}