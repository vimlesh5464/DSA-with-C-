#include <iostream>
#include<vector>
#include <queue> 
#include <utility> 
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {

        // 1. Adjacency list
        vector<pair<int,int>> adj[n + 1];
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // 2. Distance + Parent arrays
        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1);

        for (int i = 1; i <= n; i++) parent[i] = i;

        // Min-heap Dijkstra
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int dis = top.first;
            int node = top.second;

            for (auto &p : adj[node]) {
                int adjNode = p.first;
                int edW = p.second;

                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // No path exist
        if (dist[n] == 1e9) return {-1};

        // 3. Reconstruct path
        vector<int> path;
        int node = n;

        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);

        reverse(path.begin(), path.end());

        // Output format: [totalWeight, then path...]
        vector<int> ans;
        ans.push_back(dist[n]);       // total weight

        for (int v : path)
            ans.push_back(v);

        return ans;
    }
};

// ----------------- Driver Code -----------------
int main() {
    int n, m;
    cin >> n >> m; // number of vertices and edges

    vector<vector<int>> edges(m, vector<int>(3));
    for(int i=0; i<m; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    Solution obj;
    vector<int> ans = obj.shortestPath(n, m, edges);

    if(ans.size() == 1 && ans[0] == -1){
        cout << -1 << endl;
    } else {
        cout << "Weight: " << ans[0] << "\nPath: ";
        for(int i=1; i<ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}

