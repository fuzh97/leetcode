/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0) return;
        bool rowFlag = false, colFlag = false;
        //遍历第一列 是否有0
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                colFlag = true;
                break;
            }
        }
        //遍历第一行 是否有0
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) {
                rowFlag = true;
                break;
            }
        }
        //遍历剩下的值，如果有0，将该元素所在的行和列均置为
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //重新遍历，如果该元素所在的行（列）第一个元素为0，则该元素为0
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (colFlag == true) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (rowFlag == true) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
    }
};
// @lc code=end
