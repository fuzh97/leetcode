/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
   public:
    string simplifyPath(string path) {
        stringstream is(path);  //初始化字符流为path
        vector<string> strs;    //实现栈，保存临时目录字符
        string ans = "", temp = "";
        while (getline(is, temp, '/')) {
            if (temp == "" || temp == ".") {
                continue;  //遇到空字符或者当前目录
            } else if (temp == ".." && !strs.empty()) {
                strs.pop_back();  //遇到上级目录且目录数组中不为空
            } else if (temp != "..") {
                strs.push_back(temp);  //其余情况表示当前截取的部分为目录名，入栈
            }
        }
        for (string str : strs) {
            ans += "/" + str;
        }
        if (ans.empty()) {
            return "/";  //空目录
        }
        return ans;
    }
};
// @lc code=end
