#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
           const long long INF = 1e18;
          // Distance matrix for 26 letters
          vector<vector<long long>> d(26, vector<long long>(26, INF));
  
          // Distance to itself = 0
          for (int i = 0; i < 26; i++) {
              d[i][i] = 0;
          }
  
          // Build graph
          for (int i = 0; i < original.size(); i++) {
              int u = original[i] - 'a';
              int v = changed[i] - 'a';
              d[u][v] = min(d[u][v], (long long)cost[i]);
          }
  
          // Floyd–Warshall
          for (int k = 0; k < 26; k++) {
              for (int i = 0; i < 26; i++) {
                  for (int j = 0; j < 26; j++) {
                      if (d[i][k] < INF && d[k][j] < INF) {
                          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                      }
                  }
              }
          }
  
          // Calculate total cost
          long long total = 0;
  
          for (int i = 0; i < source.length(); i++) {
              int src = source[i] - 'a';
              int dest = target[i] - 'a';
  
              if (src != dest) {
                  if (d[src][dest] == INF) {
                      return -1; // conversion not possible
                  }
                  total += d[src][dest];
              }
          }
  
          return total;
  
      }
  };
int main() {

    string source, target;
    cin >> source >> target;

    int n;
    cin >> n;

    vector<char> original(n), changed(n);
    vector<int> cost(n);

    for (int i = 0; i < n; i++) {
        cin >> original[i] >> changed[i] >> cost[i];
    }

    Solution sol;
    long long ans = sol.minimumCost(source, target, original, changed, cost);

    cout << ans << "\n";

    return 0;
}
