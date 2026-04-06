# Find whether path exist.py - Python skeleton converted from C++

# Original C++ code:
# // Find whether path exist
# // Difficulty: MediumAccuracy: 45.09%Submissions: 97K+Points: 4Average Time: 20m
# 
# // Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
# // The description of cells is as follows:
# 
# //     A value of cell 1 means Source.
# //     A value of cell 2 means Destination.
# //     A value of cell 3 means Blank cell.
# //     A value of cell 0 means Wall (blocked cell which we cannot traverse).
# 
# // Note: There are only a single source and a single destination.
#  
# 
# // Examples :
# 
# // Input: grid = {{3,0,3,0,0},{3,0,0,0,3},{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
# // Output: 0
# // Explanation: The grid is-
# // 3 0 3 0 0 
# // 3 0 0 0 3 
# // 3 3 3 3 3 
# // 0 2 3 0 0 
# // 3 0 0 1 3 
# // There is no path to reach at (3,1) i,e at destination from (4,3) i,e source.
# 
# // Input: grid = {{1,3},{3,2}}
# // Output: 1
# // Explanation: The grid is-
# // 1 3
# // 3 2
# // There is a path from (0,0) i,e source to (1,1) i,e destination.
# 
# // Expected Time Complexity: O(n2)
# // Expected Auxiliary Space: O(n2)
#  
# 
# // Constraints:
# // 1 ≤ n ≤ 500
# #include <iostream>
# // #include <list>
# #include<vector>
# #include<queue>
# using namespace std;
# 
# class Solution {
# public:
#     // DFS function
#     bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
#         int n = grid.size();
# 
#         // Out of bounds
#         if(i < 0 || j < 0 || i >= n || j >= n)
#             return false;
# 
#         // Blocked cell or visited
#         if(grid[i][j] == 0 || vis[i][j])
#             return false;
# 
#         // Destination
#         if(grid[i][j] == 2)
#             return true;
# 
#         vis[i][j] = true;
# 
#         // Explore 4 directions
#         return dfs(i+1, j, grid, vis) ||
#                dfs(i-1, j, grid, vis) ||
#                dfs(i, j+1, grid, vis) ||
#                dfs(i, j-1, grid, vis);
#     }
# 
#     // Function to check if path exists from source to destination
#     bool is_Possible(vector<vector<int>>& grid) {
#         int n = grid.size();
#         vector<vector<bool>> vis(n, vector<bool>(n, false)); // 2D visited array
# 
#         // Find source cell (value 1)
#         for(int i = 0; i < n; i++) {
#             for(int j = 0; j < n; j++) {
#                 if(grid[i][j] == 1) {
#                     // Start DFS from source
#                     return dfs(i, j, grid, vis);
#                 }
#             }
#         }
# 
#         return false; // Source not found
#     }
# };
# 
# int main() {
#     int n;
#     cout << "Enter grid size (n x n): ";
#     cin >> n;
# 
#     vector<vector<int>> grid(n, vector<int>(n));
#     cout << "Enter grid values row by row (0=blocked, 1=source, 2=destination, 3=open path):\n";
# 
#     for(int i = 0; i < n; i++) {
#         for(int j = 0; j < n; j++) {
#             cin >> grid[i][j];
#         }
#     }
# 
#     Solution sol;
#     if(sol.is_Possible(grid))
#         cout << "true\n";
#     else
#         cout << "false\n";
# 
#     return 0;
# }
# 
# 
# bool bfs(int si, int sj, vector<vector<int>>& grid) {
# 
#     int n = grid.size();
#     vector<vector<bool>> vis(n, vector<bool>(n, false));
# 
#     queue<pair<int,int>> q;
#     q.push({si, sj});
#     vis[si][sj] = true;
# 
#     // 4 directions
#     int dx[4] = {1, -1, 0, 0};
#     int dy[4] = {0,  0, 1, -1};
# 
#     while(!q.empty()) {
# 
#         auto [x, y] = q.front();
#         q.pop();
# 
#         // destination found
#         if(grid[x][y] == 2) return true;
# 
#         // move in all 4 directions
#         for(int k = 0; k < 4; k++){
#             int nx = x + dx[k];
#             int ny = y + dy[k];
# 
#             // valid moves
#             if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
#                grid[nx][ny] != 0 && !vis[nx][ny])
#             {
#                 vis[nx][ny] = true;
#                 q.push({nx, ny});
#             }
#         }
#     }
# 
#     return false;
# }
# 
# int main() {
#     int n;
#     cin >> n;
# 
#     vector<vector<int>> grid(n, vector<int>(n));
#     int si = -1, sj = -1;
# 
#     // input + find source
#     for(int i = 0; i < n; i++){
#         for(int j = 0; j < n; j++){
#             cin >> grid[i][j];
#             if(grid[i][j] == 1){
#                 si = i;
#                 sj = j;
#             }
#         }
#     }
# 
#     // BFS check
#     if(bfs(si, sj, grid))
#         cout << "1\n";   // Path exists
#     else
#         cout << "0\n";   // Path does not exist
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
