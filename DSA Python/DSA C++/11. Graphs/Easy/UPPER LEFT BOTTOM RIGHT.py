# UPPER LEFT BOTTOM RIGHT.py - Python skeleton converted from C++

# Original C++ code:
# // Problem Statement
# 
# // Samriddha is on a desert which is in the form of 2D grid, of dimensions n*m, i.e it has n rows and m columns. The grid can have two types of entries 1 or 0. 0 means that the cell is occupied by sand and 1 means that the cell is occupied by water. We are interested in the water bodies. There could be 0 or more than 0 water bodies. A water body is a group of adjacent cells surrounded by either a sand body or boundary of the grid.
# 
# // The following 4 cells are adjacent to (i,j) : (i+1,j), (i-1,j), (i,j+1), (i,j-1).
# 
# // For each water body, output the upper left cell and bottom right cell.
# 
# // NOTE : Assume 0- based indexing.
# 
#  
# 
# // Input Format
# 
# // First line contains two space separated integers denoting n and m.
# 
# // There are n lines and each line contains m space separated integers.
# 
# // Output Format
# 
# // Each line should contain 4 space separated integers.
# 
# // The number of lines would be equal to the number of water bodies.
# 
# // Output a single integer.
# 
# // Constraints
# 
# // 1<=n,m<=300.
# 
# // Sample Testcase 0
# 
# // Testcase Input
# // 4 5
# // 1 0 0 1 0
# // 0 1 1 0 1
# // 1 1 0 0 1
# // 0 0 1 0 0
# // Testcase Output
# // 0 0 0 0
# // 0 3 0 3
# // 1 1 2 1
# // 1 4 2 4
# // 3 2 3 2
# // Explanation
# 
# 
# // The input grid represents a binary matrix of size 4x5.
# 
# // There are multiple clusters of '1's:
# 
# // Cluster 1: (0, 0) to (0, 0)
# 
# // Cluster 2: (1, 1) to (2, 2)
# 
# // Cluster 3: (2, 0) to (2, 1)
# 
# // Cluster 4: (3, 2) to (3, 2)
# 
# 
# 
# // Sample Testcase 1
# 
# // Testcase Input
# // 2 3
# // 0 0 0
# // 0 0 0
# // Testcase Output
# // Explanation
# 
# 
# // The input grid represents a binary matrix of size 2x3.
# 
# // There are no clusters of '1's, so the output is empty as no boundary coordinates are found.
# 
# #include <iostream>
# #include <vector>
# #include <queue>
# using namespace std;
# 
# void user_logic(int n, int m, vector<vector<int>> &grid) {
#     vector<vector<bool>> visited(n, vector<bool>(m, false));
# 
#     int dx[4] = {-1, 1, 0, 0};
#     int dy[4] = {0, 0, -1, 1};
# 
#     for (int i = 0; i < n; i++) {
#         for (int j = 0; j < m; j++) {
#             if (grid[i][j] == 1 && !visited[i][j]) {
#                 queue<pair<int,int>> q;
#                 q.push({i,j});
#                 visited[i][j] = true;
# 
#                 int min_row = i, max_row = i;
#                 vector<int> min_col_per_row(n, m);
#                 vector<int> max_col_per_row(n, -1);
# 
#                 while(!q.empty()) {
#                     auto [x,y] = q.front(); q.pop();
# 
#                     min_row = min(min_row, x);
#                     max_row = max(max_row, x);
# 
#                     min_col_per_row[x] = min(min_col_per_row[x], y);
#                     max_col_per_row[x] = max(max_col_per_row[x], y);
# 
#                     for(int dir = 0; dir < 4; dir++) {
#                         int nx = x + dx[dir];
#                         int ny = y + dy[dir];
#                         if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
#                             if(grid[nx][ny] == 1 && !visited[nx][ny]) {
#                                 visited[nx][ny] = true;
#                                 q.push({nx, ny});
#                             }
#                         }
#                     }
#                 }
# 
#                 // Upper-left: topmost row
#                 int min_col_top_row = min_col_per_row[min_row];
#                 // Bottom-right: bottommost row
#                 int max_col_bottom_row = max_col_per_row[max_row];
# 
#                 cout << min_row << " " << min_col_top_row << " "
#                      << max_row << " " << max_col_bottom_row << endl;
#             }
#         }
#     }
# }
# 
# int main() {
#     int n, m;
#     cin >> n >> m;
#     vector<vector<int>> grid(n, vector<int>(m));
#     for(int i=0;i<n;i++)
#         for(int j=0;j<m;j++)
#             cin >> grid[i][j];
# 
#     user_logic(n,m,grid);
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
