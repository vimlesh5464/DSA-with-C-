#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Complexity Analysis of Breadth-First Search (BFS) Algorithm

//     Time Complexity: O(V + E), BFS explores all the vertices and edges in the graph. In the worst 
//    case, it visits every vertex and edge once. Therefore, the time complexity of BFS is O(V + E), 
//    where V and E are the number of vertices and edges in the given graph. 

//     Auxiliary Space: O(V), BFS uses a queue to keep track of the vertices that need to be visited. 
//     In the worst case, the queue can contain all the vertices in the graph. Therefore, the space 
//     complexity of BFS is O(V).


// BFS from given source s
void bfs(vector<vector<int>>& adj, int s, 
        vector<bool>& visited, vector<int> &res) {

    // Create a queue for BFS
    queue<int> q; 

    // Mark source node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    // Iterate over the queue
    while (!q.empty()) {

        // Dequeue a vertex and store it
        int curr = q.front(); 
        q.pop();
        res.push_back(curr);

        // Get all adjacent vertices of the dequeued 
        // vertex curr If an adjacent has not been 
        // visited, mark it visited and enqueue it
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}
                      
// Perform BFS for the entire graph which maybe
// disconnected
vector<int> bfsDisconnected(vector<vector<int>>& adj) {
    int V = adj.size();

    // create an array to store the traversal
    vector<int> res;

    // Initially mark all the vertices as not visited
    vector<bool> visited(V, false); 

    // perform BFS for each node
    for (int i = 0; i < adj.size(); ++i) {
        if (!visited[i]) {
            bfs(adj, i, visited, res);
        }
    }

    return res;
}

int main()  {

    vector<vector<int>> adj = { {1, 2}, {0}, {0},
                                {4}, {3, 5}, {4}};
    vector<int> ans = bfsDisconnected(adj);
    for(auto i:ans) {
        cout<<i<<" ";
    }
    return 0;
}