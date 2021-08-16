/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
   private:
    vector<vector<string>> ret;  //最终答案
    vector<vector<int>> dp;      //保存是否为回文串
    vector<string> ans;          //保存临时字符串
    int len;

   public:
    void dfs(const string& s, int i) {
        if (i == len) {
            ret.push_back(ans);
            return;
        }
        //回溯判断字串是否是回文串
        for (int j = i; j < len; j++) {
            if (dp[i][j] == 1) {
                ans.push_back(s.substr(i, j - i + 1));  //s[i,j]为回文串加入答案
                dfs(s, j + 1);                          //从j+1开始继续寻找
                ans.pop_back();                         //回溯
            }
        }
    }
    vector<vector<string>> partition(string s) {
        //动态规划判断每一个字串是否是回文串
        len = s.size();
        if (len == 0) {
            return ret;
        }
        dp.assign(len, vector<int>(len, 0));  //dp[i][j]=1表示s[i,j]为回文串
        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;  //只有一个元素为回文串
            if (i < len - 1 && s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;  //两个连续的相同元素
            }
        }
        for (int l = 3; l <= len; l++) {
            for (int i = 0; i + l - 1 < len; i++) {
                int j = i + l - 1;  //判断s[i,i+l-1]是否为回文串
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                }
            }
        }
        dfs(s, 0);
        return ret;
    }
};
// @lc code=end
