/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        /*
    未进行过任何操作；
    只进行过一次买操作；
    进行了一次买操作和一次卖操作，即完成了一笔交易；
    在完成了一笔交易的前提下，进行了第二次买操作；
    完成了全部两笔交易。
    */
        int n = prices.size();
        int buy_1 = -prices[0], sell_1 = 0, buy_2 = -prices[0], sell_2 = 0;
        for (int i = 1; i < n; i++) {
            buy_1 = max(buy_1, -prices[i]);
            sell_1 = max(sell_1, buy_1 + prices[i]);
            buy_2 = max(buy_2, sell_1 - prices[i]);
            sell_2 = max(sell_2, buy_2 + prices[i]);
        }
        return sell_2;
    }
};
// @lc code=end
