/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        queue<int> q;
        vector<bool> visited(s.size() + 1, false);
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                int start = q.front();
                q.pop();
                for (string nextWord : wordDict) {
                    int len = nextWord.length();
                    if (s.length() < start + len)
                        continue;  //如果起点位置加上当前位置已经超出本身长度
                    if (nextWord == s.substr(start))
                        return true;  //下一个单词刚好为最后一个单词
                    if (visited[start + len]) continue;  //该位置已经访问过
                    if (s.substr(start, len) == nextWord) {  //判断能否匹配
                        q.push(start + len);
                        visited[start + len] = true;
                        // break;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end
