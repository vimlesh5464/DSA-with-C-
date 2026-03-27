// Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

// The matrix contains only two possible values:

//     0: A blocked cell through which the rat cannot travel.
//     1: A free cell that the rat can pass through.

// Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
// If no path exists, return an empty list.

// Note: Return the final result vector in lexicographically smallest order.

// Examples:

// Input: maze[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
// Output: ["DDRDRR", "DRDDRR"]
// Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

// Input: maze[][] = [[1, 0], [1, 0]]
// Output: []
// Explanation: No path exists as the destination cell (1, 1) is blocked.

// Input: maze[][] = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
// Output: ["DDRR", "RRDD"]
// Explanation: The rat has two possible paths to reach the destination: DDRR and RRDD.

// Constraints:
// 2 ≤ n ≤ 5
// 0 ≤ maze[i][j] ≤ 1
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // Function to check if the cell is within maze and valid to move
    bool isSafe(int x, int y, int n, vector<vector<int>> &maze, 
                vector<vector<int>> &visited) {
        return (x >= 0 && x < n && y >= 0 && y < n && 
                maze[x][y] == 1 && visited[x][y] == 0);
    }

    // Function to solve maze using backtracking
    void solve(int x, int y, int n, vector<vector<int>> &maze, 
               vector<vector<int>> &visited, string path, 
               vector<string> &res) {

        // If destination reached, store the path
        if (x == n - 1 && y == n - 1) {
            res.push_back(path);
            return;
        }

        // Mark the cell visited
        visited[x][y] = 1;

        // Try moving Down
        if (isSafe(x + 1, y, n, maze, visited)) {
            solve(x + 1, y, n, maze, visited, path + "D", res);
        }
        // Try moving Left
        if (isSafe(x, y - 1, n, maze, visited)) {
            solve(x, y - 1, n, maze, visited, path + "L", res);
        }
        // Try moving Right
        if (isSafe(x, y + 1, n, maze, visited)) {
            solve(x, y + 1, n, maze, visited, path + "R", res);
        }
        // Try moving Up
        if (isSafe(x - 1, y, n, maze, visited)) {
            solve(x - 1, y, n, maze, visited, path + "U", res);
        }

        // Backtrack: unmark cell as visited
        visited[x][y] = 0;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> res;
        int n = maze.size(); // ✅ Define n
        vector<vector<int>> visited(n, vector<int>(n, 0));

        if (maze[0][0] == 1) {
            solve(0, 0, n, maze, visited, "", res);
        }

        return res; 
    }
};

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    Solution obj;
    vector<string> ans = obj.ratInMaze(maze);
    for (auto path : ans) cout << path << " ";
    cout << endl;
    return 0;
}

class Solution {
  public:
    void solve(int x, int y, int n, vector<vector<int>> &maze, 
               vector<vector<int>> &visited, string path, 
               vector<string> &res) {

        // If destination is reached
        if (x == n - 1 && y == n - 1) {
            res.push_back(path);
            return;
        }

        // Mark current cell as visited
        visited[x][y] = 1;

        // Move Down
        if (x + 1 < n && maze[x + 1][y] == 1 && !visited[x + 1][y]) {
            solve(x + 1, y, n, maze, visited, path + "D", res);
        }
        // Move Left
        if (y - 1 >= 0 && maze[x][y - 1] == 1 && !visited[x][y - 1]) {
            solve(x, y - 1, n, maze, visited, path + "L", res);
        }
        // Move Right
        if (y + 1 < n && maze[x][y + 1] == 1 && !visited[x][y + 1]) {
            solve(x, y + 1, n, maze, visited, path + "R", res);
        }
        // Move Up
        if (x - 1 >= 0 && maze[x - 1][y] == 1 && !visited[x - 1][y]) {
            solve(x - 1, y, n, maze, visited, path + "U", res);
        }

        // Backtrack: unmark the cell
        visited[x][y] = 0;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> res;
        int n = maze.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));

        // Start only if the start cell is open
        if (maze[0][0] == 1) {
            solve(0, 0, n, maze, visited, "", res);
        }

        return res;
    }
};

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    Solution obj;
    vector<string> paths = obj.ratInMaze(maze);

    if (paths.empty()) cout << "No path found\n";
    else {
        for (auto &p : paths) cout << p << " ";
        cout << endl;
    }
    return 0;
}
