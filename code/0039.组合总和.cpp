/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
   public:
    vector<int> temp;  //保存临时答案
    void dfs(vector<vector<int>>& ans, vector<int>& candidates, int target, int sum, int n, int index) {
        if (sum == target) {
            ans.push_back(temp);  //保存结果
            return;
        }
        if (index == n || sum > target)
            return;  //剪枝，当已经处理完n个数或者sum大于target时不再继续
        //选index号数
        temp.push_back(candidates[index]);
        dfs(ans, candidates, target, sum + candidates[index], n, index);
        //不选index号数
        temp.pop_back();
        dfs(ans, candidates, target, sum, n, index + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;  //保存答案
        int n = candidates.size();
        dfs(ans, candidates, target, 0, n, 0);
        return ans;
    }
};
// @lc code=end
