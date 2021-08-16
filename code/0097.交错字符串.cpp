/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start

class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length()) {
            return false;
        }
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;  //初始化左上角为0
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0) {
                    dp[0][j] = (s2[j - 1] == s3[j - 1] && dp[0][j - 1] == true);
                } else if (j == 0) {
                    dp[i][0] = (s1[i - 1] == s3[i - 1] && dp[i - 1][0] == true);
                } else {
                    dp[i][j] = ((dp[i - 1][j] == true && s3[i + j - 1] == s1[i - 1]) || (dp[i][j - 1] == true && s3[i + j - 1] == s2[j - 1]));
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
