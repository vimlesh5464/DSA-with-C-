// Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.

// Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.

// If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will always stay inside the ‘GRID’.

// Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.
// Example:

// Input: ‘R’ = 3, ‘C’ = 4
//        ‘GRID’ = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
// Output: 21

// Initially Alice is at the position (0,0) he can follow the path (0,0) -> (1,1) -> (2,1) and will collect 2 + 4 + 6 = 12 chocolates.

// Initially Bob is at the position (0, 3) and he can follow the path (0, 3) -> (1,3) -> (2, 3) and will colllect 2 + 2 + 5 = 9 chocolates.

// Hence the total number of chocolates collected will be 12 + 9 = 21. there is no other possible way to collect a greater number of chocolates than 21.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :

// 1 <= ‘T’ <= 10
// 2 <= 'R', 'C' <= 50
// 0 <= 'GRID[i][j]'<= 10^2
// Time Limit: 1sec

// Sample Input 1 :

// 2
// 3 4
// 2 3 1 2
// 3 4 2 2
// 5 6 3 5
// 2 2
// 1 1
// 1 2

// Sample Output 1 :

// 21
// 5

// Explanation Of Sample Input 1 :

// For the first test case, Initially Alice is at the position (0, 0) he can follow the path (0, 0) -> (1, 1) -> (2, 1) and will collect 2 + 4 + 6 = 12 chocolates.

// Initially Bob is at the position (0, 3) and he can follow the path (0, 3) -> (1, 3) -> (2, 3) and will collect 2 + 2 + 5 = 9 chocolates.

// Hence the total number of chocolates collected will be 12 + 9 = 21.

// For the second test case, Alice will follow the path (0, 0) -> (1, 0) and Bob will follow the path (0, 1) -> (1, 1). total number of chocolates collected will be 1 + 1 + 1 + 2 = 5

// Sample Input 2 :

// 2
// 2 2
// 3 7
// 7 6
// 3 2
// 4 5
// 3 7
// 4 2

// Sample Output 2 :

// 23
// 25


#include <iostream>
#include<vector>
using namespace std;

// Class to solve Ninja and his friends using memoization
class Solution {
public:
    // Recursive function with memoization
    int solve(int i, int j1, int j2, int n, int m,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {
        // Out of boundary check
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9;
        
        // Base case: last row
        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        // If already computed return it
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        // Take chocolates from current cell(s)
        int maxi = -1e9;
        int curr = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
        
        // Try all 9 moves
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int ans = curr + solve(i + 1, j1 + dj1, j2 + dj2,
                                       n, m, grid, dp);
                maxi = max(maxi, ans);
            }
        }
        // Store result
        return dp[i][j1][j2] = maxi;
    }
    
    // Main function to call
    int maximumChocolates(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(0, 0, m - 1, n, m, grid, dp);
    }
};

// Driver code
int main() {
    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };
    int n = grid.size(), m = grid[0].size();
    Solution obj;
    cout << obj.maximumChocolates(n, m, grid) << endl;
    return 0;
}
