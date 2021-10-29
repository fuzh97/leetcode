/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start
class Solution {
   public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        unsigned tmp = 1;
        while (tmp <= n) {
            tmp <<= 1;
        }
        return (n ^ (tmp - 1));
    }
};
// @lc code=end
