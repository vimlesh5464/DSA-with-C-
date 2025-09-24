#include <iostream>
#include<vector>
#include <queue> 
#include <utility> 
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list (1-indexed)
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // undirected
        }

        // Step 2: Distance and parent arrays
        vector<int> dist(n+1, INT_MAX);
        vector<int> parent(n+1);
        for(int i=1; i<=n; i++) parent[i] = i;

        dist[1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 1}); // {distance, node}

        // Step 3: Dijkstra
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int d = it.first;
            int node = it.second;

            if(d > dist[node]) continue; // stale entry

            for(auto &nbr : adj[node]){
                int adjNode = nbr.first;
                int edgeW = nbr.second;

                if(d + edgeW < dist[adjNode]){
                    dist[adjNode] = d + edgeW;
                    parent[adjNode] = node; // track path
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // Step 4: Check if path exists
        if(dist[n] == INT_MAX) return {-1};

        // Step 5: Reconstruct path
        vector<int> path;
        int node = n;
        while(node != parent[node]){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());

        // Step 6: Insert total weight at beginning
        path.insert(path.begin(), dist[n]);
        return path;
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

