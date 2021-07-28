/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
   public:
    string addBinary(string a, string b) {
        int len1 = a.length() - 1, len2 = b.length() - 1, carry = 0;
        string ans;
        while (len1 >= 0 || len2 >= 0 || carry != 0) {
            int n1 = len1 >= 0 ? a[len1] - '0' : 0;
            int n2 = len2 >= 0 ? b[len2] - '0' : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 2;
            ans = to_string(sum % 2) + ans;
            len1--;
            len2--;
        }
        return ans;
    }
};
// @lc code=end
