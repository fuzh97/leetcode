/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
   public:
    void dfs(vector<int>& nums, uint target, int index, int& ans) {
        if (target == 0 && index == nums.size()) {
            ans++;
            return;
        }
        if (index >= nums.size()) return;
        dfs(nums, target - nums[index], index + 1, ans);
        dfs(nums, target + nums[index], index + 1, ans);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0;
        dfs(nums, S, 0, ans);
        return ans;
    }
};
// @lc code=end
