/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
   public:
    int climbStairs(int n) {
        vector<int> ans;
        ans.push_back(1);
        ans.push_back(1);
        for (int i = 2; i <= n; i++) {
            ans.push_back(ans[i - 1] + ans[i - 2]);
        }
        return ans[n];
    }
};
// @lc code=end
