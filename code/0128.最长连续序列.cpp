/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include <cstdio>
#include <unordered_set>
using namespace std;
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        int len = nums.size(), longestStreak = 0;
        for (int i = 0; i < len; i++) {
            num_set.insert(nums[i]);
        }
        for (int i = 0; i < len; i++) {
            if (num_set.count(nums[i] - 1) == 0) {
                //不存在左边相邻的元素，为左区间端点
                int currentNum = nums[i];
                int currentStreak = 1;
                while (num_set.count(currentNum + 1) != 0) {
                    currentNum++;
                    currentStreak++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};
// @lc code=end
