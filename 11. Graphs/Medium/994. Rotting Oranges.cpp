#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size(), n = grid[0].size();
        int days = 0, total = 0, count = 0;

        queue<pair<int, int>> rotten;

        // Step 1: Count total oranges and enqueue all initially rotten ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) total++;
                if (grid[i][j] == 2) rotten.push({i, j});
            }
        }

        // Directions: up, down, left, right
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        // Step 2: BFS to rot adjacent fresh oranges
        while (!rotten.empty()) {
            int k = rotten.size();
            count += k;
            while (k--) {
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                        continue;
                    grid[nx][ny] = 2; // rot it
                    rotten.push({nx, ny});
                }
            }
            if (!rotten.empty()) days++;
        }

        return (total == count) ? days : -1;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    vector<vector<int>> grid2 = {
        {2,1,1},
        {0,1,1},
        {1,0,1}
    };

    vector<vector<int>> grid3 = {
        {0,2}
    };

    cout << "Example 1 Output: " << sol.orangesRotting(grid1) << endl; // Expected: 4
    cout << "Example 2 Output: " << sol.orangesRotting(grid2) << endl; // Expected: -1
    cout << "Example 3 Output: " << sol.orangesRotting(grid3) << endl; // Expected: 0

    return 0;
}
