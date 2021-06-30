/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        long long temp = 0;
        int y = x;
        while (x != 0) {
            temp = temp * 10 + x % 10;
            x /= 10;
        }
        if ((int)temp != y) return false;
        return true;
    }
};
// @lc code=end
