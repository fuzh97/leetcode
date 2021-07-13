/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> temp;
    void dfs(vector<vector<int>>& ans, vector<int>& candidates, int index, int target, int sum) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        if (sum > target || index == candidates.size()) {
            return;
        }
        for (int i = index; i < candidates.size() && sum <= target; i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                //这个数字在这一轮已经用过了，跳过
                continue;
            }
            temp.push_back(candidates[i]);
            dfs(ans, candidates, i + 1, target, sum + candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        dfs(ans, candidates, 0, target, 0);
        return ans;
    }
};
// @lc code=end
