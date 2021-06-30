/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, size = nums.size();
        for (auto i : nums) {
            sum += i;
        }
        if (sum % 2 != 0) return false;  //和为奇数，一定不能分割
        sum /= 2;                        //背包容量
        vector<vector<bool>> dp(size + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= size; i++) {
            dp[i][0] = true;  //背包容量为0，表示已经装满
        }
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j - nums[i - 1] < 0) {  //背包容量不足以装下第i-1件物品
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[size][sum];
    }
};
// @lc code=end
