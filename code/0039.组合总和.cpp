/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> temp;
    void dfs(vector<vector<int>>& ans, vector<int>& candidates, int index, int target, int sum) {  //index为当前标记，target为目标，sum为当前temp中的和
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        if (sum > target || index == candidates.size()) {
            //剪枝
            return;
        }
        for (int i = index; i < candidates.size() && sum <= target; i++) {
            temp.push_back(candidates[i]);
            dfs(ans, candidates, i, target, sum + candidates[i]);  //可以继续使用i
            temp.pop_back();                                       //回溯
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        dfs(ans, candidates, 0, target, 0);
        return ans;
    }
};
// @lc code=end
