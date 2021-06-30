/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
   public:
    vector<int> temp;
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<bool>& used, int depth, int len) {
        if (depth == len) {
            ans.push_back(temp);
            return;
        } else {
            for (int i = 0; i < len; i++) {
                if (used[i]) continue;  // used已经用过，跳过
                temp.push_back(nums[i]);
                used[i] = true;
                dfs(ans, nums, used, depth + 1, len);
                temp.pop_back();  //回溯
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        vector<bool> used(len, false);
        dfs(ans, nums, used, 0, len);
        return ans;
    }
};
// @lc code=end
