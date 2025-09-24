#include <iostream>
#include<vector>
#include <queue> 
using namespace std;
///this is not work negative weight and negative cycle 

// Time Complexity: O( E log(V) ), Where E = Number of edges and V = Number of Nodes.

// Space Complexity: O( |E| + |V| ), Where E = Number of edges and V = Number of Nodes.
// User function template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Build adjacency list with weights
        vector<vector<pair<int,int>>> adj(V);
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // if graph is undirected
        }
        
        // Step 2: Distance array + min-heap
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src}); // {distance, node}
        
        // Step 3: Dijkstra loop
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // Relax edges
            for(auto &nbr : adj[node]){
                int adjNode = nbr.first;
                int edgeW   = nbr.second;
                
                if(dis + edgeW < dist[adjNode]){
                    dist[adjNode] = dis + edgeW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};

// -------------------- Driver Code --------------------
int main() {
    int V, E;
    cin >> V >> E; // number of vertices and edges
    
    vector<vector<int>> edges;
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    int src;
    cin >> src;
    
    Solution obj;
    vector<int> ans = obj.dijkstra(V, edges, src);
    
    for(int i = 0; i < V; i++){
        if(ans[i] == INT_MAX) cout << "INF ";
        else cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}
