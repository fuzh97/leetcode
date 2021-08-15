/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
   public:
    int calculate(string s) {
        stack<int> nums, ops;
        int len = s.size(), sign = 1, ans = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                continue;
            } else if (s[i] == '+' || s[i] == '-') {
                sign = s[i] == '+' ? 1 : -1;
            } else if (s[i] == '(') {
                //暂存答案
                nums.push(ans);
                ops.push(sign);
                ans = 0;
                sign = 1;
            } else if (s[i] == ')') {
                ans = nums.top() + ans * ops.top();
                nums.pop();
                ops.pop();
            } else if (isdigit(s[i])) {
                int temp = s[i] - '0';
                while (i < len - 1 && isdigit(s[i + 1])) {
                    temp = temp * 10 + (s[i + 1] - '0');
                    i++;
                }
                ans += temp * sign;
            }
        }
        return ans;
    }
};
// @lc code=end
