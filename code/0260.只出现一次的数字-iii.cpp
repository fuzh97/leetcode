/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0, len = nums.size();
        for (int i = 0; i < len; i++) {
            temp ^= nums[i];  //从头到尾异或
        }
        int div = 1;  //记录异或结果中第一位为1的位
        int a = 0, b = 0;
        while ((div & temp) == 0) {
            div <<= 1;  //左移一位
        }
        for (int i = 0; i < len; i++) {
            //该位为1的分一组，为0的分另外一组
            if (div & nums[i]) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }
        return vector<int>{a, b};
    }
};
// @lc code=end
