/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
   public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 0 || len == 1) return s;
        int start = 0, max_length = 1, length = 1;
        vector<vector<int> > dp(len, vector<int>(len));
        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
            if (i < len - 1 && s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                length = 2;
                if (length > max_length) {
                    max_length = length;
                    start = i;  //更新起始位置，保存最大长度
                }
            }
        }
        for (int l = 3; l <= len; l++) {
            for (int i = 0; i + l - 1 < len; i++) {
                int j = i + l - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    length = l;
                    if (length > max_length) {
                        max_length = length;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, max_length);
    }
};
// @lc code=end
