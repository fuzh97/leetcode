/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size(), ans = 0;
        for (int i = 0; i <= len; i++) {
            ans ^= i;
        }
        for (int i = 0; i < len; i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};
// @lc code=end
