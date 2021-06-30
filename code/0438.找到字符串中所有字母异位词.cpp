/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, windows;
        for (char c : p) need[c]++;
        int left = 0, right = 0, valid = 0;
        vector<int> ans;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                windows[c]++;
                if (windows[c] == need[c]) {
                    valid++;  //找见一个符合要求的
                }
            }
            while (right - left >= p.size()) {
                if (valid == need.size()) {
                    ans.push_back(left);
                }
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (windows[d] == need[d]) {
                        valid--;
                    }
                    windows[d]--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
