/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
   public:
    int reverse(int x) {
        long long n = 0;
        while (x != 0) {
            n = n * 10 + x % 10;
            x /= 10;
        }
        if (n > INT_MAX || n < INT_MIN)
            return 0;
        else
            return n;
    }
};
// @lc code=end
