#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}}; // 4 directions

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    grid[i][j] = '0'; // mark as visited
                    queue<pair<int,int>> q;
                    q.push({i,j});

                    while(!q.empty()) {
                        auto [x,y] = q.front();
                        q.pop();

                        for(auto &dir : directions) {
                            int nx = x + dir[0];
                            int ny = y + dir[1];

                            if(nx >=0 && ny >=0 && nx < m && ny < n && grid[nx][ny]=='1') {
                                grid[nx][ny] = '0'; // mark visited
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of islands: " << sol.numIslands(grid) << endl;
    // Output: 3

    return 0;
}
