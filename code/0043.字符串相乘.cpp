/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int len1 = num1.size(), len2 = num2.size();
        vector<int> res(len1 + len2);
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int temp = mul + res[p2];  //叠加到之前的res上。
                res[p2] = temp % 10;       //低位
                res[p1] += temp / 10;      //高位
            }
        }
        int i = 0;
        string ans;
        while (i < res.size() && res[i] == 0) {
            i++;  //去掉之前没有用到的位（高位为0）
        }
        for (; i < res.size(); i++) {
            ans += res[i] + '0';  //计算结果转换为字符串
        }
        return ans;
    }
};
// @lc code=end
