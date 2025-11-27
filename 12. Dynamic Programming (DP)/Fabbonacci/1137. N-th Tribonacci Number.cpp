#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      int tribonacci(int n) {
          if (n == 0) return 0;
          if (n == 1 || n == 2) return 1;
  
          vector<int> dp(n + 1);
          dp[0] = 0;
          dp[1] = 1;
          dp[2] = 1;
  
          for (int i = 3; i <= n; i++) {
              dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
          }
  
          return dp[n];
      }
  };
  
  class Solution {
    public:
        int tribonacci(int n) {
            if (n == 0) return 0;
            if (n == 1 || n == 2) return 1;
    
            int a = 0, b = 1, c = 1;
    
            for (int i = 3; i <= n; i++) {
                int curr = a + b + c;
                a = b;
                b = c;
                c = curr;
            }
    
            return c;
        }
    };
    int main() {
      Solution s;
      int n;
      cout << "Enter n: ";
      cin >> n;
  
      cout << "Tribonacci(" << n << ") = " << s.tribonacci(n) << endl;
  
      return 0;
  }    