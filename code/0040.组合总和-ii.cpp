/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
   public:
    vector<int> temp;
    vector<vector<int>> ans;
    void dfs(vector<int> &candidates, int target, int index) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i = index; i < candidates.size() && target - candidates[i] >= 0;
             i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;  //去重
            temp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1);
            temp.pop_back();  //回溯
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return ans;
    }
};
// @lc code=end
