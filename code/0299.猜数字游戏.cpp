/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
   public:
    string getHint(string secret, string guess) {
        int countA = 0, countB = 0;
        vector<int> count(10, 0);
        for (int i = 0; i < secret.size(); i++) {
            count[secret[i] - '0']++;  //统计secret中每个字符的个数
        }
        for (int i = 0; i < guess.size(); i++) {
            if (count[guess[i] - '0'] > 0) {
                countB++;
                count[guess[i] - '0']--;
            }
        }
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                countA++;
                countB--;
            }
        }
        return to_string(countA) + "A" + to_string(countB) + "B";
    }
};
// @lc code=end
