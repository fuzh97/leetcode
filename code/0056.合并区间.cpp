/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int size = intervals.size(), count = 0;
        sort(intervals.begin(), intervals.end());  //按左区间大小排序
        count++;
        for (int i = 0; i < size; i++) {
            int left = intervals[i][0], right = intervals[i][1];
            if (ans.size() == 0 || ans.back()[1] < left)
                ans.push_back({left, right});
            else
                ans.back()[1] = max(ans.back()[1], right);
        }
        return ans;
    }
};
// @lc code=end
