/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
   public:
    int minMoves(vector<int>& nums) {
        int minNum = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for (int num : nums) {
            ans += num - minNum;
        }
        return ans;
    }
};
// @lc code=end
