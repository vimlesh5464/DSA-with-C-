# Grid Ways.py - Python skeleton converted from C++

# Original C++ code:
# #include <iostream>
# #include<vector>
# using namespace std;
# 
# //solution 2
# int factorial(int n) {
#   int res = 1;
#   for (int i = 1; i <= n; i++)
#       res *= i;
#   return res;
# }
# 
# int gridWays(int n, int m) {
#   int num = factorial(n + m - 2);
#   int den = factorial(n - 1) * factorial(m - 1);
#   return num / den;
# }
# ////solution 1
# int gridWays(int i, int j, int n, int m, vector<vector<int>> &grid) {
#   // Out of bounds or blocked cell
#   if(i >= n || j >= m || grid[i][j] == 1) return 0;
# 
#   // Reached bottom-right cell
#   if(i == n - 1 && j == m - 1) return 1;
# 
#   // Move Down + Move Right
#   return gridWays(i + 1, j, n, m, grid) + gridWays(i, j + 1, n, m, grid);
# }
# 
# int uniquePaths(vector<vector<int>> &grid) {
#   int n = grid.size();
#   int m = grid[0].size();
#   return gridWays(0, 0, n, m, grid);
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
