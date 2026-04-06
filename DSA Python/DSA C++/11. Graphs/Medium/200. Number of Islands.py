# 200. Number of Islands.py - Python skeleton converted from C++

# Original C++ code:
# // Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.
# 
# // Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
# 
# // Examples:
# 
# // Input: grid[][] = [['L', 'L', 'W', 'W', 'W'], 
# //                 ['W', 'L', 'W', 'W', 'L'], 
# //                 ['L', 'W', 'W', 'L', 'L'], 
# //                 ['W', 'W', 'W', 'W', 'W'], 
# //                 ['L', 'W', 'L', 'L', 'W']]
# // Output: 4
# // Explanation:
# // The image below shows all the 4 islands in the grid.
#  
# 
# // Input: grid[][] = [['W', 'L', 'L', 'L', 'W', 'W', 'W'], 
# //                 ['W', 'W', 'L', 'L', 'W', 'L', 'W']]
# // Output: 2
# // Expanation:
# // The image below shows 2 islands in the grid.
#  
# 
# // Constraints:
# // 1 ≤ n, m ≤ 500
# // grid[i][j] = {'L', 'W'}
# 
# #include<iostream>
# #include<list>
# #include<queue>
# #include<vector>
# using namespace std;
# class Solution {
#   public:
#       void dfs(vector<vector<char>>& grid, int i, int j,vector<vector<bool>> &vis) {
#           int m = grid.size();
#           int n = grid[0].size();
#   
#           // Base case: Out of bounds or water cell
#           if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0'|| vis[i][j]) {
#               return;
#           }
#   
#           // Mark the cell as visited by changing it to '0'
#           vis[i][j] = true;
#   
#           // Explore all 4 adjacent directions
#           dfs(grid, i + 1, j,vis); // Down
#           dfs(grid, i - 1, j,vis); // Up
#           dfs(grid, i, j + 1,vis); // Right
#           dfs(grid, i, j - 1,vis); // Left
#       }
#   
#       int numIslands(vector<vector<char>>& grid) {
#           if (grid.empty()) return 0;
#   
#           int count = 0;
#           int m = grid.size();
#           int n = grid[0].size();
#   
#           vector<vector<bool>>vis(m,vector<bool>(n,false));
#           // Traverse every cell in the grid
#           for (int i = 0; i < m; ++i) {
#               for (int j = 0; j < n; ++j) {
#                   // If it's land, start a DFS and increase island count
#                   if (grid[i][j] == '1' && !vis[i][j]) {
#                       dfs(grid, i, j,vis);
#                       count++;
#                   }
#               }
#           }
#           return count;
#       }
#   };
#   class Solution {
#     public:
#        
#         
#         void dfs(int i, int j, vector<vector<char>>& grid,int n,int m) {
#             // Boundary + water check
#             if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 'W')
#                 return;
#             
#             // Mark visited
#             grid[i][j] = 'W';
#             
#             // 8 directions
#             int dx[] = {-1,-1,-1,0,0,1,1,1};
#             int dy[] = {-1,0,1,-1,1,-1,0,1};
#             
#             for(int k = 0; k < 8; k++) {
#                 dfs(i + dx[k], j + dy[k], grid,n,m);
#             }
#         }
#         
#         int countIslands(vector<vector<char>>& grid) {
#             int n = grid.size();
#             int m = grid[0].size();
#             
#             int count = 0;
#             
#             for(int i = 0; i < n; i++) {
#                 for(int j = 0; j < m; j++) {
#                     if(grid[i][j] == 'L') {
#                         count++;        // New island found
#                         dfs(i, j, grid,n,m);
#                     }
#                 }
#             }
#             
#             return count;
#         }
#     };
#   
# int main() {
#     int m, n;
#     cin >> m >> n;
# 
#     vector<vector<char>> grid(m, vector<char>(n));
# 
#     for (int i = 0; i < m; i++) {
#         for (int j = 0; j < n; j++) {
#             cin >> grid[i][j];
#         }
#     }
# 
#     Solution sol;
#     cout << sol.countIslands(grid);
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
