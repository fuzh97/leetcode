/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
#include <cstdio>
#include <map>
#include <queue>
#include <vector>
using namespace std;
//dfs
class Solution {
   public:
    int row, col;
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= row || y < 0 || y >= col || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) {
            return;
        }
        row = board.size(), col = board[0].size();
        for (int i = 0; i < row; i++) {
            dfs(board, i, 0);
            dfs(board, i, col - 1);
        }
        for (int j = 1; j < col - 1; j++) {
            dfs(board, 0, j);
            dfs(board, row - 1, j);
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';  //已经标记的表示没有被围起来，还原
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';  //其余的O替换为X
                }
            }
        }
    }
};

//bfs
class Solution {
   public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) {
            return;
        }
        int row = board.size(), col = board[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') {
                q.emplace(i, 0);
            }
            if (board[i][col - 1] == 'O') {
                q.emplace(i, col - 1);
            }
        }
        for (int j = 1; j < col - 1; j++) {
            if (board[0][j] == 'O') {
                q.emplace(0, j);
            }
            if (board[row - 1][j] == 'O') {
                q.emplace(row - 1, j);
            }
        }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            board[x][y] = 'A';  //标记
            for (int i = 0; i < 4; i++) {
                int mx = x + dx[i], my = y + dy[i];
                if (mx < 0 || mx >= row || my < 0 || my >= col || board[mx][my] != 'O') {
                    continue;
                }
                q.emplace(mx, my);
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';  //还原
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';  //替换
                }
            }
        }
    }
};
// @lc code=end
