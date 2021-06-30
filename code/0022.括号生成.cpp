/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int lc = 0, rc = 0;  //左括号和右括号的个数
        dfs(res, "", n, lc, rc);
        return res;
    }
    void dfs(vector<string> &res, string path, int n, int lc, int rc) {
        if (rc > lc || rc > n || lc > n) return;
        if (lc == rc && lc == n) {
            res.push_back(path);
            return;
        }
        dfs(res, path + '(', n, lc + 1, rc);
        dfs(res, path + ')', n, lc, rc + 1);
    }
};
// @lc code=end
