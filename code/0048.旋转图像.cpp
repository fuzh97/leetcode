/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);  //转置矩阵
            }
        }
        for (int i = 0; i < row; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
// @lc code=end
