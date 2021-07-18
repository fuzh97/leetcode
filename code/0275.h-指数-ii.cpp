/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
   public:
    int hIndex(vector<int>& citations) {
        int len = citations.size(), ans = 0;
        int left = 0, right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= (len - mid)) {
                //引用的次数 >= 论文的篇数
                //此时满足要求，向左收缩区间看看能不能找见数量更多的论文符合要求
                right = mid - 1;
                ans = len - mid;

            } else {
                //引用的次数 < 论文的篇数
                //不符合要求，答案在右区间中
                left = mid + 1;
            }
        }
        return ans;
    }
};
