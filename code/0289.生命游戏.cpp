/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> DX = {0, 0, 1, -1, 1, 1, -1, -1};
    vector<int> DY = {1, -1, 0, 0, 1, -1, 1, -1};
    vector<vector<int>> ans;
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0) {
            return;
        }
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int count = 0;  //记录活细胞的个数
                for (int k = 0; k < 8; k++) {
                    int x = i + DX[k], y = j + DY[k];
                    if (x < 0 || x >= n || y < 0 || y >= m) {
                        continue;  //边界
                    }
                    if (abs(board[x][y]) == 1) {
                        count++;
                    }
                }
                if (count < 2 && board[i][j] == 1) {
                    board[i][j] = -1;  //少于两个活细胞，过去是活的现在死了
                }
                if (count >= 2 && count <= 3 && board[i][j] == 1) {
                    board[i][j] = 1;  //过去是活的现在不变
                }
                if (count > 3 && board[i][j] == 1) {
                    board[i][j] = -1;  //多余三个活细胞，过去是活的现在死了
                }
                if (count == 3 && board[i][j] == 0) {
                    board[i][j] = 2;  //恰好三个活细胞，死细胞复活
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] > 0) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};
// @lc code=end
