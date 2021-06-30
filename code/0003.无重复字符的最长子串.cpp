/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, length = 0, max_length = 0;
        int s_size = s.size();
        unordered_map<char, int> mp;
        while (end < s_size) {
            char temp = s[end];
            if (mp.find(temp) != mp.end() && mp[temp] >= start) {
                start = mp[temp] + 1;
                length = end - start;
            }
            mp[temp] = end;
            end++, length++;
            if (length > max_length) max_length = length;
        }
        return max_length;
    }
};
// @lc code=end
