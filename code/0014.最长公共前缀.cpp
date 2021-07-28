/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        int len = strs[0].size(), count = strs.size();
        for (int i = 0; i < len; i++) {
            char temp = strs[0][i];
            for (int j = 1; j < count; j++) {
                if (i == strs[j].size() || temp != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
// @lc code=end
