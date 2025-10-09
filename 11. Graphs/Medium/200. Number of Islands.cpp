#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;


class Solution {
  public:
      void dfs(vector<vector<char>>& grid, int i, int j) {
          int m = grid.size();
          int n = grid[0].size();
  
          // Base case: Out of bounds or water cell
          if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') {
              return;
          }
  
          // Mark the cell as visited by changing it to '0'
          grid[i][j] = '0';
  
          // Explore all 4 adjacent directions
          dfs(grid, i + 1, j); // Down
          dfs(grid, i - 1, j); // Up
          dfs(grid, i, j + 1); // Right
          dfs(grid, i, j - 1); // Left
      }
  
      int numIslands(vector<vector<char>>& grid) {
          if (grid.empty()) return 0;
  
          int count = 0;
          int m = grid.size();
          int n = grid[0].size();
  
          // Traverse every cell in the grid
          for (int i = 0; i < m; ++i) {
              for (int j = 0; j < n; ++j) {
                  // If it's land, start a DFS and increase island count
                  if (grid[i][j] == '1') {
                      dfs(grid, i, j);
                      count++;
                  }
              }
          }
          return count;
      }
  };
  
int main() {
    Solution sol;

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of islands: " << sol.numIslands(grid) << endl;
    // Output: 3

    return 0;
}
