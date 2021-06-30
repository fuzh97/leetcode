/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> row[9];
        unordered_map<int, int> cloumn[9];
        unordered_map<int, int> box[9];
        int temp, box_idx;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                temp = board[i][j] - '0';         //将char类型变为int处理
                box_idx = (i / 3) * 3 + (j / 3);  //确定box的顺序
                if (board[i][j] != '.') {
                    if (row[i].find(temp) != row[i].end() ||
                        cloumn[j].find(temp) != cloumn[j].end() ||
                        box[box_idx].find(temp) != box[box_idx].end()) {
                        return false;
                    } else {
                        row[i][temp] = 1;
                        cloumn[j][temp] = 1;
                        box[box_idx][temp] = 1;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
