/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
   public:
    int findComplement(int num) {
        if (num == 0) {
            return 1;
        }
        unsigned tmp = 1;
        while (tmp <= num) {
            tmp <<= 1;
        }
        return (num ^ (tmp - 1));
    }
};
// @lc code=end
