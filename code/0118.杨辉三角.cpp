/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; i++) {
            res[i].resize(i + 1);  //分配大小
            res[i][0] = 1;         //第一个元素
            for (int j = 1; j < i; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];  //错位相加
            }
            res[i][i] = 1;  //最后一位
        }
        return res;
    }
};
// @lc code=end
