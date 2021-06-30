/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp; //键位元素，值位元素的位置
        int temp = nums.size();
        for (int i = 0; i < temp; i++)
        {
            if (mp.find(target - nums[i]) != mp.end())
            {
                return {mp[target - nums[i]], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end
