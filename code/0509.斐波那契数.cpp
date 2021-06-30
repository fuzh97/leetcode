/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
   public:
    int fib(int n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else {
            int a = 0, b = 1, ans;
            for (int i = 2; i <= n; i++) {
                ans = a + b;
                a = b;
                b = ans;
            }
            return ans;
        }
    }
};
// @lc code=end
