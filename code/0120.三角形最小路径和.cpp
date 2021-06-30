/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        vector<int> dp(len + 1, 0);
        for (int i = len - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};
// @lc code=end
