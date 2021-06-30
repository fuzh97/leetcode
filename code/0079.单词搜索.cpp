/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
   public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int w) {
        if (board[i][j] != word[w]) return false;
        if (w == word.length() - 1) return true;
        char tmp = board[i][j];
        board[i][j] = 0;
        if ((i - 1 >= 0 && dfs(board, word, i - 1, j, w + 1)) ||
            (j + 1 <= board[0].size() - 1 &&
             dfs(board, word, i, j + 1, w + 1)) ||
            (i + 1 <= board.size() - 1 && dfs(board, word, i + 1, j, w + 1)) ||
            (j - 1 >= 0 && dfs(board, word, i, j - 1, w + 1)))
            return true;
        board[i][j] = tmp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++)
                if (dfs(board, word, i, j, 0)) return true;
        }
        return false;
    }
};
