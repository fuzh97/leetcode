/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> temp;
    void dfs(vector<vector<int>>& ans, vector<int>& candidates, int index, int target, int sum, int k) {
        if (sum == target && temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        if (sum > target || index == candidates.size() || temp.size() > k) {
            return;
        }
        for (int i = index; i < candidates.size() && sum <= target && temp.size() <= k; i++) {
            temp.push_back(candidates[i]);
            dfs(ans, candidates, i + 1, target, sum + candidates[i], k);
            temp.pop_back();  //回溯
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> candidates{1, 2, 3, 4, 5, 6, 7, 8, 9};
        dfs(ans, candidates, 0, n, 0, k);
        return ans;
    }
};
// @lc code=end
