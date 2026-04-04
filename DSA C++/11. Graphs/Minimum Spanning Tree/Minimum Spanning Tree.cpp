// Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is provided as a list of edges, where each edge is represented as [u, v, w], indicating an edge between vertex u and vertex v with edge weight w.

// Input: V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
 
// Output: 4
// Explanation:

// The Spanning Tree resulting in a weight
// of 4 is shown above.

// Input: V = 2, E = 1, Edges = [[0 1 5]]

 

// Output: 5 
// Explanation: Only one Spanning Tree is possible which has a weight of 5.

// Constraints:
// 2 ≤ V ≤ 1000
// V-1 ≤ E ≤ (V*(V-1))/2
// 1 ≤ w ≤ 1000
// The graph is connected and doesn't contain self-loops & multiple edges.
#include <iostream>
#include<vector>
using namespace std;

// Function to find MST weight using Prim's Algorithm
int primsMST(int V, vector<vector<pair<int,int>>> &adj) {
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> vis(V, 0);
    
    pq.push({0, 0}); // {weight, node}
    
    int sum = 0;
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        int wt = it.first;
        int node = it.second;
        
        if(vis[node]) continue;
        
        vis[node] = 1;
        sum += wt;
        
        for(auto &nbr : adj[node]){
            int adjNode = nbr.first;
            int edW = nbr.second;
            
            if(!vis[adjNode]){
                pq.push({edW, adjNode});
            }
        }
    }
    
    return sum;
}

int main() {
    int V, E;
    cin >> V >> E;
    
    vector<vector<pair<int,int>>> adj(V);
    
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    int result = primsMST(V, adj);
    cout << "MST Weight: " << result << endl;
    
    return 0;
}