/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) return {};
        int height = matrix.size(), width = matrix[0].size();
        int up = 0, down = height - 1, left = 0, right = width - 1;
        while (true) {
            for (int i = left; i <= right; i++) {  //从左至右
                ans.push_back(matrix[up][i]);
            }
            if (++up > down) break;
            for (int j = up; j <= down; j++) {  //从上至下
                ans.push_back(matrix[j][right]);
            }
            if (--right < left) break;
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[down][i]);
            }
            if (--down < up) break;
            for (int j = down; j >= up; j--) {
                ans.push_back(matrix[j][left]);
            }
            if (++left > right) break;
        }
        return ans;
    }
};
// @lc code=end
