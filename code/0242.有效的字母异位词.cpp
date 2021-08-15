/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
   public:
    bool isAnagram(string s, string t) {
        vector<int> mp(26, 0);
        int len1 = s.size(), len2 = t.size();
        if (len1 != len2) {
            return false;
        }
        for (int i = 0; i < len1; i++) {
            mp[s[i] - 'a']++;
        }
        for (int i = 0; i < len2; i++) {
            mp[t[i] - 'a']--;
            if (mp[t[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
