/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
   public:
    void reverse(string& s, int start, int end) {
        int i = start, j = end;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    void removeExtraSapces(string& s) {
        int slowIndex = 0, fastIndex = 0;
        //去掉字符串前面的空格
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        for (; fastIndex < s.size(); fastIndex++) {
            if (fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] && s[fastIndex] == ' ') {
                //与上一个相同还是空格，继续跳过
                //只有两个空格的话才会删除，只有一个空格的话继续替换下·
                continue;
            } else {
                //不是空格开始移动
                s[slowIndex] = s[fastIndex];
                slowIndex++;
            }
        }

        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') {
            //去掉末尾的空格(如果只有一个空格不能删除)
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex);
        }
    }
    string reverseWords(string s) {
        removeExtraSapces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0, end = 0;
        bool entry = false;
        for (int i = 0; i < s.size(); i++) {
            //反转单词
            if (!entry) {
                start = i;  //单词起始位置
                entry = true;
            }
            if (entry && s[i] == ' ' && s[i - 1] != ' ') {
                end = i - 1;  //单词终止位置
                entry = false;
                reverse(s, start, end);
            }
            if (entry == true && (i == (s.size() - 1)) && s[i] != ' ') {
                end = i;
                entry = false;
                reverse(s, start, end);
            }
        }
        return s;
    }
};
// @lc code=end
