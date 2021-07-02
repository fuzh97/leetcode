/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), total_tanK = 0, curr_tank = 0, start = 0;
        for (int i = 0; i < n; i++) {
            total_tanK += gas[i] - cost[i];
            curr_tank += gas[i] - cost[i];
            if (curr_tank < 0) {
                //归零，从下一站开始。
                start = i + 1;
                curr_tank = 0;
            }
        }
        if (total_tanK >= 0) {
            return start;  //可以顺利返回
        } else {
            return -1;
        }
    }
};
// @lc code=end
