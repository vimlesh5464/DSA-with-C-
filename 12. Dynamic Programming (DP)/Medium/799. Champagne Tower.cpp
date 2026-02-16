#include <vector>
#include <iostream>
using namespace std;


class Solution {
  public:
      double solve(int r, int c, int poured, 
                   vector<vector<double>>& memo) {
  
          if (c < 0 || c > r) 
              return 0.0;
  
          if (r == 0 && c == 0)
              return poured;
  
          if (memo[r][c] != -1.0)
              return memo[r][c];
  
          double left = solve(r - 1, c - 1, poured, memo);
          double right = solve(r - 1, c, poured, memo);
  
          double fromLeft = max(0.0, (left - 1.0) / 2.0);
          double fromRight = max(0.0, (right - 1.0) / 2.0);
  
          memo[r][c] = fromLeft + fromRight;
          return memo[r][c];
      }
  
      double champagneTower(int poured, int query_row, int query_glass) {
          vector<vector<double>> memo(query_row + 1,
                                      vector<double>(query_row + 1, -1.0));
  
          return min(1.0, solve(query_row, query_glass, poured, memo));
      }
  };

  class Solution {
    public:
        double helper(int poured, int query_row, int query_glass) {
            
            vector<vector<double>> dp(query_row + 1, 
                                      vector<double>(query_row + 1, 0.0));
    
            dp[0][0] = poured;
    
            for (int r = 0; r < query_row; r++) {
                for (int c = 0; c <= r; c++) {
    
                    if (dp[r][c] > 1.0) {
                        double overflow = (dp[r][c] - 1.0) / 2.0;
    
                        dp[r+1][c] += overflow;
                        dp[r+1][c+1] += overflow;
    
                        dp[r][c] = 1.0;  // cap at 1
                    }
                }
            }
    
            return min(1.0, dp[query_row][query_glass]);
        }
    
        double champagneTower(int poured, int query_row, int query_glass) {
            return helper(poured, query_row, query_glass);
        }
    };