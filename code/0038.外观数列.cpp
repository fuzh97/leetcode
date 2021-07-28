/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start

#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string countAndSay(int n) {
        string arr = "1";
        if (n == 1) {
            return arr;
        }
        for (int i = 1; i < n; i++) {
            char word = arr[0];
            int num = 1;
            string temp = "";  //第n+1轮生成的字符串
            for (int j = 1; j < arr.size(); j++) {
                if (arr[j] == word) {
                    //如果相等则累加计数
                    num++;
                } else if (arr[j] != word) {
                    //如果不相等则更新临时字符串，同时即将word，num更新
                    char num_char = num + '0';
                    temp += num_char;  //数量
                    temp += word;      //字符
                    word = arr[j];     //更新
                    num = 1;
                }
            }
            //处理旧序列中的最后一个字符
            char num_char = num + '0';
            temp += num_char;
            temp += word;
            arr = temp;  //本轮新生成的序列，做下一轮的输入
        }
        return arr;
    }
};
// @lc code=end
