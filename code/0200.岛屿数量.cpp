/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
   public:
    int X[4] = {0, 0, 1, -1};
    int Y[4] = {1, -1, 0, 0};
    void dfs(vector<vector<char>>& grid, vector<vector<char>>& vis, int cur_i,
             int cur_j) {
        if (cur_i < 0 || cur_i >= grid.size() || cur_j < 0 ||
            cur_j >= grid[0].size() || vis[cur_i][cur_j] == true ||
            grid[cur_i][cur_j] == '0')
            return;
        vis[cur_i][cur_j] = true;
        for (int i = 0; i < 4; i++) {
            int now_i = cur_i + X[i], now_j = cur_j + Y[i];
            // vis[now_i][now_j] = true;
            dfs(grid, vis, now_i, now_j);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int count = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<char>> vis(n, vector<char>(m));
        for (int i = 0; i < n; i++) {  //初始化
            for (int j = 0; j < m; j++) {
                vis[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == false && grid[i][j] == '1') {
                    count++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return count;
    }
};
// @lc code=end
