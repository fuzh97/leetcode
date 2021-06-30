#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
   public:
    vector<int> temp;
    void dfs(vector<vector<int>>& ans, vector<int>& nums, int cur) {
        ans.push_back(temp);
        for (int i = cur; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            dfs(ans, nums, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(ans, nums, 0);
        return ans;
    }
};
// @lc code=end
