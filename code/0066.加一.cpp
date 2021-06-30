/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        for (int i = len - 1; i >= 0; i--) {
            digits[i] += 1;
            digits[i] %= 10;
            if (digits[i] != 0) return digits;
        }
        vector<int> digits_new(len + 1);
        digits_new[0] = 1;
        return digits_new;
    }
};
// @lc code=end
