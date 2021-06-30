/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
/*
dfs
class Solution {
   public:
    void dfs(vector<int>& coins, int amount, int c_index, int count, int& ans) {
        if (amount == 0) {
            ans = min(ans, count);
            return;
        }
        if (c_index == coins.size()) return;
        for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--) {
            dfs(coins, amount - k * coins[c_index], c_index + 1, count + k,
                ans);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.begin(), coins.end());
        reverse(coins.begin(), coins.end());
        int ans = INT_MAX;
        dfs(coins, amount, 0, 0, ans);
        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};
*/
// dp
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        int size = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < size; j++) {
                if (coins[j] <= i) {
                    int remain = i - coins[j];
                    if (dp[remain] != INT_MAX)
                        dp[i] = min(dp[i], dp[remain] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX)
            return -1;
        else
            return dp[amount];
    }
};
// @lc code=end
