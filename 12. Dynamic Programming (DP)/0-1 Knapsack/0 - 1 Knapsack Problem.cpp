#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int helper(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp) {
        // Base case
        if (n == 0 || W == 0) return 0;
        
        // Already calculated
        if (dp[n][W] != -1) return dp[n][W];
        
        if (wt[n-1] <= W) {
            // Option 1: include item
            int include = val[n-1] + helper(W - wt[n-1], val, wt, n-1, dp);
            // Option 2: exclude item
            int exclude = helper(W, val, wt, n-1, dp);
            return dp[n][W] = max(include, exclude);
        } 
        else {
            // Cannot include this item
            return dp[n][W] = helper(W, val, wt, n-1, dp);
        }
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        return helper(W, val, wt, n, dp);
    }
};

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    vector<int> val(n), wt(n);
    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) cin >> val[i];
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) cin >> wt[i];

    Solution sol;
    cout << "Maximum value in Knapsack = " << sol.knapsack(W, val, wt) << endl;
    return 0;
}
