/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
/*
//dfs
class Solution {
 public:
  void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int cities,
           int i) {  //是否连接，是否访问，
    for (int j = 0; j < cities; j++) {
      if (isConnected[i][j] == 1 && visited[j] == 0) {
        //如果i,j之间有边并且j没有访问过
        visited[j] = 1;                        //访问j
        dfs(isConnected, visited, cities, j);  //递归
      }
    }
  }
  int findCircleNum(vector<vector<int>>& isConnected) {
    int cities = isConnected.size();  //城市数量
    vector<int> visited(cities);      //访问标记数组
    int provinces = 0;                //省份数量
    for (int i = 0; i < cities; i++) {
      if (visited[i] == 0) {
        dfs(isConnected, visited, cities, i);  //从第i个点开始遍历
        provinces++;  //一次dfs代表一次联通分量，即一个省份
      }
    }
    return provinces;
  }
};
*/
/*
// bfs
class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int cities = isConnected.size();
    vector<int> visited(cities);
    int province = 0;
    queue<int> Q;
    for (int i = 0; i < cities; i++) {
      if (visited[i] == 0) {
        Q.push(i);
        while (!Q.empty()) {
          int j = Q.front();  //出队
          Q.pop();
          visited[j] = 1;  //访问队头元素
          for (int k = 0; k < cities; k++) {
            //遍历所有与j相邻的元素
            if (isConnected[j][k] == 1 && visited[k] == 0) {
              Q.push(k);  //入队。
            }
          }
        }
        province++;  //一次bfs为一个联通向量
      }
    }
    return province;
  }
};
*/
//并查集
class Solution {
 public:
  int Find(vector<int>& parent, int index) {
    if (parent[index] != index) {
      parent[index] = Find(parent, parent[index]);
    }
    return parent[index];
  }
  void Union(vector<int>& parent, int index1, int index2) {
    parent[Find(parent, index1)] = Find(parent, index2);  //合并
  }
  int findCircleNum(vector<vector<int>>& isConnected) {
    int cities = isConnected.size();
    vector<int> parent(cities);  //最开始每一个都是单独的集合
    for (int i = 0; i < cities; i++) {
      parent[i] = i;
    }
    for (int i = 0; i < cities; i++) {
      for (int j = i + 1; j < cities; j++) {
        if (isConnected[i][j] == 1) {  //两点间有联通则合并
          Union(parent, i, j);
        }
      }
    }
    int provinces = 0;
    for (int i = 0; i < cities; i++) {
      if (parent[i] == i) {
        provinces++;  //查找有几个根节点
      }
    }
    return provinces;
  }
};
// @lc code=end
