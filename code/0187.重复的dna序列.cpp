/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
   public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> ans;
        int n = s.size();
        for (int i = 0; i + 9 < n; i++) {
            string temp = s.substr(i, 10);  //当前窗口
            mp[temp]++;
        }
        for (unordered_map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            if (it->second > 1) {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};
// @lc code=end
