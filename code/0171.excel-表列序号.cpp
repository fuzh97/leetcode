/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
   public:
    int titleToNumber(string columnTitle) {
        int len = columnTitle.size(), ans = 0;
        for (int i = 0; i < len; i++) {
            int temp = columnTitle[i] - 'A' + 1;
            ans = ans * 26 + temp;
        }
        return ans;
    }
};
// @lc code=end
