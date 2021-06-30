/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m - 1, q = n - 1, s = m + n - 1, cur;
        while (p >= 0 || q >= 0) {
            if (p == -1)
                cur = nums2[q--];
            else if (q == -1)
                cur = nums1[p--];
            else if (nums1[p] > nums2[q])
                cur = nums1[p--];
            else
                cur = nums2[q--];
            nums1[s--] = cur;
        }
    }
};
// @lc code=end
