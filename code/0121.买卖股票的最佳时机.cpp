/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if (length == 0) return 0;
        int minPrice = prices[0];
        vector<int> dp(length, 0);
        for (int i = 1; i < length; i++) {
            minPrice = min(minPrice, prices[i]);  //记录最小价格
            dp[i] = max(dp[i - 1], prices[i] - minPrice);
        }
        return dp[length - 1];
    }
};
// @lc code=end
