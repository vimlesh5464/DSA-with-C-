#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        int total = 0;          // total number of oranges (fresh + rotten)
        int rottenCount = 0;    // number of oranges processed during BFS
        int days = 0;           // result: minimum time to rot all oranges

        queue<pair<int, int>> q; // BFS queue for rotten oranges

        // STEP 1: Count total oranges & push all initially rotten oranges into queue
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0) total++;   // count both fresh(1) + rotten(2)

                if(grid[i][j] == 2) {          // push rotten oranges
                    q.push({i, j});
                }
            }
        }

        // Directions (right, left, down, up)
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        // STEP 2: Multi-source BFS from initially rotten oranges
        while(!q.empty()) {

            int k = q.size();       // number of rotten oranges at current minute
            rottenCount += k;       // update oranges processed

            while(k--) {
                auto [x, y] = q.front();
                q.pop();

                // check 4-directionally adjacent cells
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    // skip invalid or non-fresh cells
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                    if(grid[nx][ny] != 1) continue;

                    // rot fresh orange → mark rotten
                    grid[nx][ny] = 2;

                    // push new rotten orange into queue
                    q.push({nx, ny});
                }
            }

            // If queue is not empty, it means new oranges got rotten,
            // so 1 minute has passed
            if(!q.empty()) days++;
        }

        // STEP 3: If processed oranges != total → some fresh remained → impossible
        return (total == rottenCount) ? days : -1;
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    // Input grid
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << obj.orangesRotting(grid); // print output

    return 0;
}
