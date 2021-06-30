/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int index = 0;
        while (index < intervals.size() && intervals[index][1] < newInterval[0]) {
            ans.push_back(intervals[index]);
            index++;
        }
        while (index < intervals.size() && intervals[index][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[index][0], newInterval[0]);
            newInterval[1] = max(intervals[index][1], newInterval[1]);
            index++;
        }
        ans.push_back(newInterval);  //将合并好的数组放入答案
        while (index < intervals.size()) {
            ans.push_back(intervals[index]);
            index++;
        }
        return ans;
    }
};
// @lc code=end

