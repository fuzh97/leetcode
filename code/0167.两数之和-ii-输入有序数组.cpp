/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start

#include <cstdio>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> ans(2);
        while (left < right) {
            int temp = numbers[left] + numbers[right];
            if (target == temp) {
                ans[0] = left + 1;
                ans[1] = right + 1;
                break;
            } else if (target > temp) {
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};
// @lc code=end
