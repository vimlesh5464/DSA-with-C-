#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;


class Solution {
public:

    bool dfsCycleHelper(int src, vector<vector<int>> &adj,
                        vector<bool>& vis, vector<bool>& recPath) {

        vis[src] = true;
        recPath[src] = true;

        for (int v : adj[src]) {

            if (!vis[v]) {
                if (dfsCycleHelper(v, adj, vis, recPath))
                    return true;
            }
            else if (recPath[v]) {
                return true;
            }
        }

        recPath[src] = false;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &adj) {

        vector<bool> vis(V,false);
        vector<bool> recPath(V,false);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfsCycleHelper(i, adj, vis, recPath))
                    return true;
            }
        }

        return false;
    }
};

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);   // directed edge
    }

    Solution obj;

    if(obj.isCyclic(V, adj))
        cout << "Cycle Present\n";
    else
        cout << "No Cycle\n";

    return 0;
}