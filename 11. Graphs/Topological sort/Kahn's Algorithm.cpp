#include <iostream>
#include<queue>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        // Step 2: Calculate indegree
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        // Step 3: Push all 0 indegree nodes
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        // Step 4: Kahn’s Algorithm
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return topo;
    }
};

int main(){

    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    Solution obj;
    vector<int> ans = obj.topoSort(V, edges);

    if(ans.size() != V){
        cout << "Cycle Present - Topological Sort Not Possible\n";
    }
    else{
        cout << "Topological Order:\n";
        for(auto it : ans){
            cout << it << " ";
        }
    }

    return 0;
}