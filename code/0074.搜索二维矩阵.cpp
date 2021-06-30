#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
/*
暴力解
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] < target) {
                    break;
                } else {
                    if (target == matrix[i][j]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
*/
// 二分
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                i--;
            } else {
                j++;
            }
        }
        return false;
    }
};
// @lc code=end
