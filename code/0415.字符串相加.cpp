/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size() - 1, len2 = num2.size() - 1, carry = 0;
        string ans = "";
        while (len1 >= 0 || len2 >= 0 || carry != 0) {
            int n1 = len1 >= 0 ? num1[len1] - '0' : 0;
            int n2 = len2 >= 0 ? num2[len2] - '0' : 0;
            int temp = n1 + n2 + carry;
            carry = temp / 10;  //进位
            ans = to_string(temp % 10) + ans;
            len1--;
            len2--;
        }
        return ans;
    }
};
// @lc code=end
