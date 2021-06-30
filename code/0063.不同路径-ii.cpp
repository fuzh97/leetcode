/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid[0].size(), n = obstacleGrid.size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[i][0] == 0)
                dp[i][0] = 1;
            else
                break;
        }
        for (int j = 0; j < m; j++) {
            if (obstacleGrid[0][j] == 0)
                dp[0][j] = 1;
            else
                break;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[i][j] == 0) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[n - 1][m - 1];
    }
};
// @lc code=end
