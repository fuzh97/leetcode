/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class Solution {
 public:
  vector<double> res;
  bool Nofand;
  void dfs(unordered_map<string, vector<pair<string, double>>>& g,
           unordered_map<string, int>& visit, string val, const string& target,
           const double& path) {  //图g，访问标志数组，起点，终点，路径长度。
    if (Nofand == false) return;
    if (val == target) {  //如果节点已经相连，则不用继续访问，直接返回
      Nofand = false;
      res.push_back(path);
      return;
    }
    for (int j = 0; j < g[val].size(); j++) {
      //检查与val相连接的点，是否已经被访问过了，没访问过继续dfs
      if (visit[g[val][j].first] == 0) {
        visit[g[val][j].first] = 1;
        dfs(g, visit, g[val][j].first, target, path * g[val][j].second);
        visit[g[val][j].first] = 0;
      }
    }
  }
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    //建图
    unordered_map<string, vector<pair<string, double>>> g;  //
    unordered_map<string, int> visit;                       //标记是否访问

    //建立无向图 a-b权值为x，则b-a权值为1/x
    for (int i = 0; i < equations.size(); i++) {
      g[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
      g[equations[i][1]].push_back(make_pair(equations[i][0], 1.0 / values[i]));
    }

    //遍历queries 计算dfs。如果相连，路径上的乘积即为答案。
    for (int i = 0; i < queries.size(); i++) {
      //如果没有找见这个点，返回-1
      if (g.find(queries[i][0]) == g.end()) {
        res.push_back(-1.0);
        continue;
      }
      Nofand = true;
      visit[queries[i][0]] = 1;
      dfs(g, visit, queries[i][0], queries[i][1], 1);
      visit[queries[i][0]] = 0;         //回溯
      if (Nofand) res.push_back(-1.0);  //两个点不相连，返回-1.
    }
    return res;
  }
};
// @lc code=end
