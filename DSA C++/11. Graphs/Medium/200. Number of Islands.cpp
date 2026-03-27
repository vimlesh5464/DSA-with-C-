#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
class Solution {
  public:
      void dfs(vector<vector<char>>& grid, int i, int j,vector<vector<bool>> &vis) {
          int m = grid.size();
          int n = grid[0].size();
  
          // Base case: Out of bounds or water cell
          if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0'|| vis[i][j]) {
              return;
          }
  
          // Mark the cell as visited by changing it to '0'
          vis[i][j] = true;
  
          // Explore all 4 adjacent directions
          dfs(grid, i + 1, j,vis); // Down
          dfs(grid, i - 1, j,vis); // Up
          dfs(grid, i, j + 1,vis); // Right
          dfs(grid, i, j - 1,vis); // Left
      }
  
      int numIslands(vector<vector<char>>& grid) {
          if (grid.empty()) return 0;
  
          int count = 0;
          int m = grid.size();
          int n = grid[0].size();
  
          vector<vector<bool>>vis(m,vector<bool>(n,false));
          // Traverse every cell in the grid
          for (int i = 0; i < m; ++i) {
              for (int j = 0; j < n; ++j) {
                  // If it's land, start a DFS and increase island count
                  if (grid[i][j] == '1' && !vis[i][j]) {
                      dfs(grid, i, j,vis);
                      count++;
                  }
              }
          }
          return count;
      }
  };
  
int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    cout << sol.numIslands(grid);

    return 0;
}
