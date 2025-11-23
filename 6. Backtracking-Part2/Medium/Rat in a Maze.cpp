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
