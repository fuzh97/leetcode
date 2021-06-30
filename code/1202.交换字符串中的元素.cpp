/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 */

// @lc code=start
class Djset {
   public:
    vector<int> parent;
    vector<int> rank;
    Djset(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    int findParent(int x) {
        if (x != parent[x]) {
            parent[x] = findParent(parent[x]);
        }
        return parent[x];
    }
    void Union(int x, int y) {
        int root_x = findParent(x), root_y = findParent(y);
        if (root_x != root_y) {
            if (rank[root_x] < rank[root_y]) swap(root_x, root_y);
            parent[root_y] = root_x;
            if (rank[root_x] == rank[root_y]) rank[x] += 1;
        }
    }
};
class Solution {
   public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int len = s.size();
        string ans;
        vector<char> temp(len);  //字符数组
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        Djset ds(len);  //实例化并查集
        for (int i = 0; i < pairs.size(); i++) {
            ds.Union(pairs[i][0], pairs[i][1]);
        }
        for (int i = 0; i < len; i++) {
            mp[ds.findParent(i)].push(s[i]);  //同一个父节点的归类到一个索引中
        }
        for (int i = 0; i < len; i++) {
            int x = ds.findParent(i);
            s[i] = mp[x].top();  //返回最后一个元素
            mp[x].pop();
        }
        return s;
    }
};
// @lc code=end
