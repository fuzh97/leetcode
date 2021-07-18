/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
   public:
    int hIndex(vector<int>& citations) {
        int len = citations.size(), tmp = 0;
        vector<int> counter(len + 1);  //记录当前引用次数的论文有几篇
        for (int i = 0; i < len; i++) {
            if (citations[i] >= len) {
                counter[len]++;
            } else {
                counter[citations[i]]++;
            }
        }   
        for (int i = len; i >= 0; i--) {
            tmp += counter[i];
            if (tmp >= i) {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end
