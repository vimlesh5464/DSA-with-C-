// Problem Statement

// Tanmay is celebrating the Diwali festival and wants to decorate their house with LED lights. He checked each bulb in the LED lights to identify which bulbs were not functioning correctly, and placed the LED lights on the floor to form a graph-like structure. 

// Given, the price of one bulb represented by the integer 'K' and an undirected graph in the form of a 2D array, can you help him determine the total cost of the non-functioning bulbs.

// The total number of LED lights is N, starting from (0  to  N).

// And non-functional bulb can be represented by the number of bulb divisible by an integer 'M' and do not count as a 0 number bulb, just because it is always functional to convey the electricity coming.

// Given lights forms a connected component
// Note:

// You have to travel in the graph from 0 integer value.
// You need to first make the undirected graph from the array in ith-index.
// Create a bond representing the Edge of a graph, or you have given the chart, then solve the problem.
 

// Input Format

// The first line of input contains a single integer K representing the price of the bulb.

// The second line of input contains a single integer N representing the total bulb.

// The third line of input contains an integer M denoting the number of bulb divisible by M.

// The fourth line of input contains the length of the 2D array.

// The fifth line of input has a 2D array.

// Output Format

// Print the total cost of a non-functional bulbs

// Constraints

// 0< K < 10^6 

// 0< N< 10^6

// 0< M< 10^3

// 2 < array.length < 10^9

// Sample Testcase 0

// Testcase Input
// 5
// 14
// 15
// 16
// 1 4
// 1 5
// 1 2
// 5 6
// 2 8
// 2 3
// 6 3
// 3 7
// 8 7
// 8 9
// 7 10
// 10 11
// 11 14
// 9 12
// 12 13
// 14 0
// Testcase Output
// 0
// Explanation

// With the help of the edges we are first creating the graph.
// Then we find how many elements divisible by m are present.
// Multiply the count with the cost of each non-functional bulb (k) and return it.
// Sample Testcase 1

// Testcase Input
// 5
// 14
// 2
// 16
// 1 4
// 1 5
// 1 2
// 5 6
// 2 8
// 2 3
// 6 3
// 3 7
// 8 7
// 8 9
// 7 10
// 10 11
// 11 14
// 9 12
// 12 13
// 14 0
// Testcase Output
// 35
// Explanation

// With the help of the edges we are first creating the graph.
// Then we find how many elements divisible by m are present.
// Multiply the count with the cost of each non-functional bulb (k) and return it.



#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int calculate_total_cost(int k, int n, int m, vector<pair<int, int>> &graph) {
  // Edge case
  if (m == 0) return 0;

  int count = n / m;
  return count * k;
}

int calculate_total_cost(int k, int n, int m, vector<pair<int, int>> &graph) {
    // Edge case
    if (m == 0) return 0;

    // Step 1: Build adjacency list
    vector<vector<int>> adj(n + 1);
    for (auto &edge : graph) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 2: BFS
    vector<bool> visited(n + 1, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    int count = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Step 3: Check condition
        if (node != 0 && node % m == 0) {
            count++;
        }

        // Step 4: Traverse neighbors
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    // Step 5: Total cost
    return count * k;
}

int main() {
    int k, n, m, len_graph;
    cin >> k >> n >> m >> len_graph;
    
    vector<pair<int, int>> graph(len_graph);
    for(int i = 0; i < len_graph; i++) {
        cin >> graph[i].first >> graph[i].second;
    }
    
    int total_cost = calculate_total_cost(k, n, m, graph);
    cout << total_cost << endl;
    return 0;
}