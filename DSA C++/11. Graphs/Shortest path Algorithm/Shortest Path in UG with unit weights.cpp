#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
  public:
  vector<int> shortestPath(vector<vector<int>>& adj, int src){
    int V = adj.size();
    vector<int> path(V, INT_MAX);
    path[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
      int node = q.front();
      q.pop();
      for(auto it : adj[node]){
        if(path[node]+1 <path[it]){
          path[it]=1+path[node];
        }
      }
    }
    vector<int> ans(V,-1);
    for(int i = 0; i < V; i++){
      if(path[i]!=INT_MAX){
        ans[i]=path[i];
      }
    }
    return ans;
  }
};

int main() {
  // Example graph (undirected or directed depending on input)
  int V = 6;  // number of vertices
  vector<vector<int>> adj(V);

  // Add edges
  adj[0] = {1, 2};
  adj[1] = {0, 3};
  adj[2] = {0, 4};
  adj[3] = {1, 5};
  adj[4] = {2, 5};
  adj[5] = {3, 4};

  Solution obj;
  int src = 0;
  vector<int> ans = obj.shortestPath(adj, src);

  cout << "Shortest distances from source " << src << ":\n";
  for (int i = 0; i < ans.size(); i++) {
      cout << "Node " << i << " -> " << ans[i] << "\n";
  }

  return 0;
}
