/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0])
                     return a[0] > b[0];
                 else if (a[0] == b[0] && a[1] != b[1])
                     return a[1] < b[1];
                 return false;
             });
        vector<vector<int>> ans;
        for (auto& tmp : people) {
            ans.insert(ans.begin() + tmp[1], tmp);
        }
        return ans;
    }
};
// @lc code=end
