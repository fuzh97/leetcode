/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <cstdio>
#include <string>
using namespace std;
class Solution {
   public:
    bool tooLarge(long long res) {
        //判断res是否超过了int范围
        if (res >= INT_MAX || res <= INT_MIN) {
            return true;
        } else {
            return false;
        }
    }
    int myAtoi(string s) {
        if (s.length() == 0) return 0;
        int idx = 0, len = s.length(), sign = 1;  //sign存储符号位，默认为正
        //1.去除前置空格
        while (idx < len && s[idx] == ' ') {
            idx++;
        }

        //2.检查下一个字符是正还是负
        //读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
        if (isdigit(s[idx]) == false && s[idx] != '-' && s[idx] != '+') {
            return 0;
        }
        if (s[idx] == '-') {
            sign = -1;  //符号位置负
        }
        if (isdigit(s[idx]) == false) {
            idx++;  //跳过符号位，处理下一个字符
        }

        //3.向后读字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
        long long res = 0;
        bool start = 0;
        while (idx < len && isdigit(s[idx])) {
            //4.将读到的数字转换为整数
            int num = s[idx] - '0';
            res = res * 10 + num;
            if (tooLarge(sign * res) == true) {
                //已经到达边界
                if (sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            idx++;
        }
        return sign * res;
    }
};
// @lc code=end
