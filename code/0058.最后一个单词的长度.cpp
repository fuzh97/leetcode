/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
#include <cstdio>
#include <string>
#include <vector>

class Solution {
   public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int count = 0, len = s.size();
        for (int i = len - 1; i >= 0; i--) {
            if (count != 0 && s[i] == ' ') {
                //不是第一次遇到空格，退出
                break;
            }
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                count++;
            }
        }
        return count;
    }
};
// @lc code=end
