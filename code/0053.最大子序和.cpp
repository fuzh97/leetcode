/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size(), ans;
        vector<int> dp(size);  // dp[i]表示以nums[i]为结尾的序列的最大和
        dp[0] = nums[0];
        ans = dp[0];
        for (int i = 1; i < size; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            if (dp[i] > ans) ans = dp[i];
        }
        return ans;
    }
};
// @lc code=end
