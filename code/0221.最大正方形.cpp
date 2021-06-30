/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == -0 || matrix[0].size() == 0) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int maxLen = 0;
        for (int i = 0; i < rows; i++) {
            dp[i][0] = matrix[i][0] - '0';
            maxLen = max(maxLen, dp[i][0]);
        }
        for (int j = 0; j < cols; j++) {
            dp[0][j] = matrix[0][j] - '0';
            maxLen = max(maxLen, dp[0][j]);
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == '0') continue;
                int len1 = dp[i - 1][j], len2 = dp[i][j - 1],
                    len3 = dp[i - 1][j - 1];
                dp[i][j] = min(min(len1, len2), len3) + 1;
                maxLen = max(dp[i][j], maxLen);
            }
        }
        return maxLen * maxLen;
    }
};
// @lc code=end
