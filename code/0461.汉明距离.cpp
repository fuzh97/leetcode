/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
   public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};
// @lc code=end
