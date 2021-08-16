/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1, mp2;
        int len = s.size(), i = 0, j = 0;
        while (i < len) {
            if (mp1.find(s[i]) == mp1.end()) {
                mp1[s[i]] = t[j];
            }
            if (mp2.find(t[j]) == mp2.end()) {
                mp2[t[j]] = s[i];
            }
            if (mp1[s[i]] != t[j] || mp2[t[j]] != s[i]) {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};
// @lc code=end
