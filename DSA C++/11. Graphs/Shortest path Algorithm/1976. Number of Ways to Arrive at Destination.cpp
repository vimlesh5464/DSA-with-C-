#include <iostream>
#include<vector>
#include <set> 
#include <queue> 
using namespace std;


class Solution {
  public:
      int countPaths(int n, vector<vector<int>>& roads) {
          // Adjacency list
          vector<vector<pair<int, long long>>> adj(n);
  
          for (auto &it : roads) {
              adj[it[0]].push_back({it[1], it[2]});
              adj[it[1]].push_back({it[0], it[2]});
          }
  
          // Min-heap: {distance, node}
          priority_queue<pair<long long, int>,
                         vector<pair<long long, int>>,
                         greater<pair<long long, int>>> pq;
  
          vector<long long> dist(n, LLONG_MAX);
          vector<int> ways(n, 0);
  
          int src = 0;
          int dst = n - 1;
  
          dist[src] = 0;
          ways[src] = 1;
          pq.push({0, src});
  
          int mod = 1e9 + 7;
  
          while (!pq.empty()) {
              long long dis = pq.top().first;
              int node = pq.top().second;
              pq.pop();
  
              if (dis > dist[node]) continue;  // skip outdated entry
  
              for (auto &it : adj[node]) {
                  int adjNode = it.first;
                  long long edW = it.second;
  
                  // Case 1: Found a shorter path
                  if (dis + edW < dist[adjNode]) {
  
                      dist[adjNode] = dis + edW;
                      ways[adjNode] = ways[node];
                      pq.push({dist[adjNode], adjNode});
                  }
                  // Case 2: Found another shortest path
                  else if (dis + edW == dist[adjNode]) {
                      ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                  }
              }
          }
  
          return ways[dst] % mod;
      }
  };
  int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of roads: ";
    cin >> m;

    vector<vector<int>> roads(m, vector<int>(3));

    cout << "Enter roads (u v time):\n";
    for (int i = 0; i < m; i++) {
        cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
    }

    Solution sol;
    int result = sol.countPaths(n, roads);

    cout << "Number of shortest paths: " << result << endl;

    return 0;
}
  