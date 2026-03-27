#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            int low = 0, high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (grid[i][mid] < 0) {
                    high = mid - 1; // look for earlier negative
                } else {
                    low = mid + 1;
                }
            }
            // low is now the index of first negative number
            count += (n - low);
        }
        return count;
    }
};

class Solution {
  public:
      int countNegatives(vector<vector<int>>& grid) {
          int m = grid.size();
          int n = grid[0].size();
          int row = 0, col = n - 1;
          int count = 0;
  
          while (row < m && col >= 0) {
              if (grid[row][col] < 0) {
                  count += (m - row); // all below are negative
                  col--;               // move left
              } else {
                  row++;               // move down
              }
          }
  
          return count;
      }
  };
// 🔹 Driver Code
int main() {
    vector<vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    };

    Solution sol;
    cout << sol.countNegatives(grid) << endl; // Output: 8
    return 0;
}
