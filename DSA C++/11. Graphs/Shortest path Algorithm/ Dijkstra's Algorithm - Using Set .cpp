#include <iostream>
#include<vector>
#include <set> 
#include <utility> 
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // if graph is undirected
        }

        // Step 2: Distance array
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Step 3: Set to store {distance, node}
        set<pair<int,int>> st;
        st.insert({0, src});

        while(!st.empty()){
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);  // remove from set

            // Relaxation
            for(auto &nbr : adj[node]){
                int adjNode = nbr.first;
                int edgeW = nbr.second;

                if(dis + edgeW < dist[adjNode]){
                    // If already in set, remove old pair
                    if(dist[adjNode] != INT_MAX){
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + edgeW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

// -------------------- Driver Code --------------------
int main() {
    int V, E;
    cin >> V >> E;
    
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
