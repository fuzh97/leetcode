/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        vector<int> ans;
        for (int num : nums) {
            if (mp.find(num) != mp.end())
                mp[num]++;
            else
                mp[num] = 1;
        }
        unordered_map<int, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            if (k == q.size()) {  //队列已满
                if (it->second > q.top().first) {
                    q.pop();
                    q.push(make_pair(it->second, it->first));
                }
            } else {  //队列未满
                q.push(make_pair(it->second, it->first));
            }
        }
        while (!q.empty()) {
            ans.push_back(q.top().second);
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
