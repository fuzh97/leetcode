/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int n = s.size(), i = 0;
        while (i < n) {
            int count = 0, j = i;
            while (j < n) {
                if (s[i] == s[j]) {
                    count++;
                    j++;
                } else {
                    break;
                }
            }
            if (count >= 3) {
                ans.push_back({i, j - 1});
            }
            i = j;
        }
        return ans;
    }
};
// @lc code=end
