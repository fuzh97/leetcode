#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
   public:
    vector<int> temp;
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<bool>& used, int depth, int len) {
        if (depth == len) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < len; i++) {
            if (used[i] == true) {
                continue;
            } else if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            } else {
                temp.push_back(nums[i]);
                used[i] = true;
                dfs(ans, nums, used, depth + 1, len);
                temp.pop_back();  //回溯
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        vector<bool> used(len, false);
        sort(nums.begin(), nums.end());
        dfs(ans, nums, used, 0, len);
        return ans;
    }
};
// @lc code=end
