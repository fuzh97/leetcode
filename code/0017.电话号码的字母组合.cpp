/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
// dfs
class Solution {
   public:
    map<char, string> mp{{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                         {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                         {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> ans;  //保存答案
    string current;
    void dfs(int index, string digits) {
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }
        for (int i = 0; i < mp[digits[index]].size(); i++) {
            current.push_back(mp[digits[index]][i]);
            dfs(index + 1, digits);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return ans;
        }
        dfs(0, digits);
        return ans;
    }
};
// @lc code=end
// bfs
class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        map<char, string> mp{{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                             {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                             {'8', "tuv"}, {'9', "wxyz"}};
        int size = digits.size();
        queue<string> q;
        //将第一个数字对应的字符串的字母挨个入队
        for (int j = 0; j < mp[digits[0]].size(); j++) {
            string str = "";
            str += mp[digits[0]][j];
            q.push(str);
        }
        for (int i = 1; i < size; i++) {
            int length = q.size();
            while (length--) {
                //依次出队，加上后面的元素再入队对应的字符
                for (int j = 0; j < mp[digits[i]].size(); j++) {
                    string s = q.front();  //获取队首字母
                    s += mp[digits[i]][j];
                    q.push(s);  //加上之后再重新入队
                }
                q.pop();  //完成一个字母，出队一个字母
            }
        }
        while (!q.empty()) {
            string temp = q.front();
            q.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};
