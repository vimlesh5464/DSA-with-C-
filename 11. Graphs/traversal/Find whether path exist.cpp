#include <iostream>
// #include <list>
#include<vector>
#include<queue>
using namespace std;

bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {

    int n = grid.size();

    // Out of bounds
    if(i < 0 || j < 0 || i >= n || j >= n)
        return false;

    // Blocked cell or visited
    if(grid[i][j] == 0 || vis[i][j])
        return false;

    // Destination
    if(grid[i][j] == 2)
        return true;

    vis[i][j] = true;

    // Explore 4 directions
    return dfs(i+1, j, grid, vis) ||
           dfs(i-1, j, grid, vis) ||
           dfs(i, j+1, grid, vis) ||
           dfs(i, j-1, grid, vis);
}


int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    int si = -1, sj = -1; // source position

    // Input matrix + find source(1)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 1){
                si = i;
                sj = j;
            }
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(n, false));

    if(dfs(si, sj, grid, vis))
        cout << "1\n";  // path exists
    else
        cout << "0\n";  // no path

    return 0;
}


bool bfs(int si, int sj, vector<vector<int>>& grid) {

    int n = grid.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    queue<pair<int,int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    // 4 directions
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0,  0, 1, -1};

    while(!q.empty()) {

        auto [x, y] = q.front();
        q.pop();

        // destination found
        if(grid[x][y] == 2) return true;

        // move in all 4 directions
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            // valid moves
            if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
               grid[nx][ny] != 0 && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    int si = -1, sj = -1;

    // input + find source
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 1){
                si = i;
                sj = j;
            }
        }
    }

    // BFS check
    if(bfs(si, sj, grid))
        cout << "1\n";   // Path exists
    else
        cout << "0\n";   // Path does not exist

    return 0;
}
