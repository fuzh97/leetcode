/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 0);
        long cur = 1;
        int mid = rowIndex / 2;
        for (int i = 0; i <= mid; ++i) {
            res[i] = cur;
            res[rowIndex - i] = cur;
            cur = cur * (rowIndex - i) / (i + 1);
        }
        return res;
    }
};
// @lc code=end
