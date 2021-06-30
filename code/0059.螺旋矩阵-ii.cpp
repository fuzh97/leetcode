/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n);
        for (int i = 0; i < ans.size(); i++) {
            ans[i].resize(n);
        }
        int up = 0, down = n - 1, left = 0, right = n - 1, num = 1;
        while (true) {
            for (int i = left; i <= right; i++) {
                ans[up][i] = num++;
            }
            if (++up > down) break;
            for (int i = up; i <= down; i++) {
                ans[i][right] = num++;
            }
            if (--right < left) break;
            for (int i = right; i >= left; i--) {
                ans[down][i] = num++;
            }
            if (--down < up) break;
            for (int i = down; i >= up; i--) {
                ans[i][left] = num++;
            }
            if (++left > right) break;
        }
        return ans;
    }
};
// @lc code=end
