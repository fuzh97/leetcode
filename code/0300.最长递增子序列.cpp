/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        vector<int> dp(size, 0);
        int maxLength = -1;
        for (int i = 0; i < size; i++) {
            dp[i] = 1;
            for (int j = 0; j < size; j++) {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};
