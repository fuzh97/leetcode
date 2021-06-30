#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
   public:
    vector<int> temp;
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<bool>& used, int cur) {
        ans.push_back(temp);
        if (cur == nums.size()) return;
        for (int i = cur; i < nums.size(); i++) {
            if (used[i] == true) {
                continue;
            } else if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            } else {
                temp.push_back(nums[i]);
                used[i] = true;
                dfs(ans, nums, used, i);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(ans, nums, used, 0);
        return ans;
    }
};
// @lc code=end
