#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);  // -1 means uncolored
        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(color[i] != -1) continue; // already visited/colored

            q.push(i);
            color[i] = 0;  // start coloring with 0

            while(!q.empty()) {
                int curr = q.front();
                q.pop();

                for(int v : graph[curr]) {
                    if(color[v] == -1) {
                        color[v] = 1 - color[curr]; // assign opposite color
                        q.push(v);
                    } else if(color[v] == color[curr]) {
                        // Adjacent nodes have same color => not bipartite
                        return false;
                    }
                }
            }
        }

        return true; // No conflicts found
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}}; // example
    if(sol.isBipartite(graph)) 
        cout << "Graph is Bipartite" << endl;
    else 
        cout << "Graph is NOT Bipartite" << endl;
    return 0;
}
