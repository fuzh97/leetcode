/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> str_ch;
        unordered_map<char, string> ch_str;
        int m = s.size(), i = 0;
        for (char c : pattern) {
            if (i >= m) {
                //单词个数少于字符个数
                return false;
            }
            int j = i;
            while (j < m && s[j] != ' ') {
                j++;
            }
            string tmp = s.substr(i, j - i);
            if (str_ch.find(tmp) != str_ch.end() && str_ch[tmp] != c) {
                return false;
            }
            if (ch_str.find(c) != ch_str.end() && ch_str[c] != tmp) {
                return false;
            }
            str_ch[tmp] = c;
            ch_str[c] = tmp;
            i = j + 1;
        }
        if (i < m) {
            //字符个数单词字符个数
            return false;
        }
        return true;
    }
};
// @lc code=end
