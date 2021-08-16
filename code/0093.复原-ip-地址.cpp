/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
   public:
    vector<string> ans;  //记录结果
    void dfs(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) {
            if (isVaild(s, startIndex, s.size() - 1)) {
                //判断最后一段是否合法
                ans.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isVaild(s, startIndex, i)) {
                //判断s[startIndex,i]区间内是否合法
                s.insert(s.begin() + i + 1, '.');  //在i的后面插入一个点
                pointNum++;
                dfs(s, i + 2, pointNum);  //判断下一个段，插入之后下一个字串的起始位置位i+2
                pointNum--;
                s.erase(s.begin() + i + 1);  //回溯，擦掉之前添加的点
            } else {
                break;  //不合法直接结束
            }
        }
    }
    bool isVaild(const string& s, int start, int end) {
        //判断字符串s在左闭右闭区间[start,end]所组成的数字是否合法
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) {
            return false;  //出现前导0
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') {  //非法字符
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) {
                return false;  //超过界限
            }
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) {
            return ans;
        }
        dfs(s, 0, 0);
        return ans;
    }
};
// @lc code=end
