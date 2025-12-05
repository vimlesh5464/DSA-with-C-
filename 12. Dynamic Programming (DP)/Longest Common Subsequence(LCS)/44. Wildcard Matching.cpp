#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int n, m;
    string s, p;
    vector<vector<int>> dp;

    bool solve(int i, int j) {
        // If already computed
        if (dp[i][j] != -1) return dp[i][j];

        // Both string and pattern finished
        if (i == n && j == m) return dp[i][j] = true;

        // Pattern finished but string not
        if (j == m) return dp[i][j] = false;

        // String finished but pattern remains
        if (i == n) {
            for (int k = j; k < m; k++) {
                if (p[k] != '*') return dp[i][j] = false;
            }
            return dp[i][j] = true;
        }

        // Match case or '?'
        if (p[j] == s[i] || p[j] == '?')
            return dp[i][j] = solve(i+1, j+1);

        // '*' case → two choices
        if (p[j] == '*')
            return dp[i][j] = solve(i, j+1) || solve(i+1, j);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        n = s.size();
        m = p.size();
        dp.assign(n+1, vector<int>(m+1, -1));
        return solve(0, 0);
    }
};

class Solution {
  public:
      bool isMatch(string s, string p) {
          int n = s.size(), m = p.size();
          vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
          
          dp[0][0] = true;
          
          // Fill first row (when s is empty)
          for(int j = 1; j <= m; j++) {
              if(p[j-1] == '*'){
                  dp[0][j] = dp[0][j-1];
              }else{
                  dp[0][j] = false;
              }
          }
          
          for(int i = 1; i <= n; i++) {
              for(int j = 1; j <= m; j++) {
                  if(p[j-1] == s[i-1] || p[j-1] == '?') {
                      dp[i][j] = dp[i-1][j-1];
                  }
                  else if(p[j-1] == '*') {
                      dp[i][j] = dp[i-1][j] || dp[i][j-1];
                  }else{
                      dp[i][j] = false;
                  }
              }
          }
          
          return dp[n][m];
      }
  };
  
  

  int main() {
    Solution sol;
    string s = "adceb", p = "*a*b";
    cout << (sol.isMatch(s, p) ? "true" : "false") << endl;
    return 0;
}
