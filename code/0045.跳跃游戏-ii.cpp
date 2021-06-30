#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
   public:
    int jump(vector<int>& nums) {
        int max_far = 0, end = 0, step = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            max_far = max(max_far, i + nums[i]);
            if (i == end) {
                //到达上次跳跃的右边界了，更新新的边界，进行下一次跳跃
                end = max_far;
                step++;
            }
        }
        return step;
    }
};
// @lc code=end
