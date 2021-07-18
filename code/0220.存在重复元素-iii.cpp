/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

class Solution {
   public:
    long size;
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        map<long, long> m;
        size = t + 1L;
        for (int i = 0; i < n; i++) {
            long u = nums[i] * 1L;
            long idx = getIdx(u);
            // 目标桶已存在（桶不为空），说明前面已有 [u - t, u + t] 范围的数字
            if (m.find(idx) != m.end()) return true;
            // 检查相邻的桶
            long l = idx - 1, r = idx + 1;
            if (m.find(l) != m.end() && abs(u - m[l]) <= t) return true;
            if (m.find(r) != m.end() && abs(u - m[r]) <= t) return true;
            // 建立目标桶
            m.insert({idx, u});
            // 移除下标范围不在 [max(0, i - k), i) 内的桶
            if (i >= k) m.erase(getIdx(nums[i - k]));
        }
        return false;
    }
    long getIdx(long u) {
        return u >= 0 ? u / size : (u + 1) / size - 1;
    }
};
// @lc code=end
