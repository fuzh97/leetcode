#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
   public:
    vector<int> temp;
    void dfs(vector<vector<int>>& ans, int n, int k, int cur) {
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        } else {
            for (int i = cur; i <= n; i++) {
                temp.push_back(i);
                dfs(ans, n, k, i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        dfs(ans, n, k, 1);
        return ans;
    }
};
// @lc code=end
