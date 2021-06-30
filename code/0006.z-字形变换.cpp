/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> temp(numRows);
        string ans;
        int flag = 1, cur = 0;
        for (int i = 0; i < s.size(); i++) {
            temp[cur] += s[i];
            cur += flag;
            if (cur == numRows - 1 || cur == 0) flag *= -1;
        }
        for (int i = 0; i < numRows; i++) {
            ans += temp[i];
        }
        return ans;
    }
};
// @lc code=end
