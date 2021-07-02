/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int num : nums) {
            int temp1 = (a & (~b) & (~num)) | ((~a) & b & num);
            int temp2 = ((~a) & b & (~num)) | ((~a) & (~b) & num);
            a = temp1;
            b = temp2;
        }
        return b;
    }
};
// @lc code=end
