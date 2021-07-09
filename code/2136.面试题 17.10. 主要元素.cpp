/*
 * @lc app=leetcode.cn id=2136 lang=cpp
 *
 * [2136] 面试题 17.10. 主要元素
 */

// @lc code=start
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size(), count = 1, cur = nums[0];
        if (nums.size() == 0) {
            return -1;
        }
        for (int i = 1; i < len; i++) {
            if (nums[i] == cur) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    cur = nums[i];
                    count = 1;
                }
            }
        }
        count = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] == cur) {
                count++;
            }
        }
        if (count > (len / 2)) {
            return cur;
        }
        return -1;
    }
};
// @lc code=end