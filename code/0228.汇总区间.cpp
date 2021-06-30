/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i = 0, n = nums.size(), low, high;
        while (i < n) {
            low = i;
            i++;
            while (i < n && nums[i] == nums[i - 1] + 1) i++;
            high = i - 1;
            string temp = to_string(nums[low]);
            if (low < high) temp = temp + "->" + to_string(nums[high]);
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end
