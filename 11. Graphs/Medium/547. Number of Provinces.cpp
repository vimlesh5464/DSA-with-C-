#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    void dfs(int u, vector<vector<int>>& g, vector<int>& vis) {
        vis[u] = 1;
        for(int v = 0; v < g.size(); v++) {
            if(g[u][v] == 1 && !vis[v]) {
                dfs(v, g, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                count++;
                dfs(i, isConnected, vis);
            }
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    Solution sol;
    cout << sol.findCircleNum(isConnected);

    return 0;
}

