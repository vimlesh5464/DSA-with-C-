// Given a string str consisting of lowercase english alphabets, the task is to find the number of distinct subsequences of the string
// Note: Answer can be very large, so, ouput will be answer modulo 109+7.

// Examples:

// Input: str = "gfg"
// Output: 7
// Explanation: 
// The seven distinct subsequences are "", "g", "f", "gf", "fg", "gg" and "gfg" .

// Input: str = "ggg"
// Output: 4
// Explanation: 
// The four distinct subsequences are "", "g", "gg", "ggg".

// Constraints:
// 1 ≤ |str| ≤ 105
// str contains lower case English alphabets

#include <iostream>
#include<vector>
#include<set>
using namespace std;



class Solution {
  public:
      void generateSubseq(int index, string &str, string current, set<string> &st) {
          if(index == str.size()) {
              st.insert(current); // add the subsequence
              return;
          }
  
          // Option 1: include str[index]
          generateSubseq(index + 1, str, current + str[index], st);
  
          // Option 2: exclude str[index]
          generateSubseq(index + 1, str, current, st);
      }
  
      int distinctSubseq(string &str) {
          set<string> st;
          string current = "";
          generateSubseq(0, str, current, st);
          return st.size(); // number of distinct subsequences
      }
  };
  
  class Solution {
    public:
        const int MOD = 1e9 + 7;
    
        int helper(int i, string &str, vector<int> &dp, vector<int> &last) {
            if(i < 0) return 1; // base case: empty subsequence
    
            if(dp[i] != -1) return dp[i];
    
            // count of subsequences including str[i]
            int count = (2LL * helper(i-1, str, dp, last)) % MOD;
    
            // if str[i] appeared before, subtract subsequences counted before last occurrence
            if(last[str[i]-'a'] != -1) {
                int idx = last[str[i]-'a'];
                count = (count - helper(idx-1, str, dp, last) + MOD) % MOD;
            }
    
            // update last occurrence
            last[str[i]-'a'] = i;
    
            return dp[i] = count;
        }
    
        int distinctSubseq(string &str) {
            int n = str.size();
            vector<int> dp(n, -1);
            vector<int> last(26, -1); // last occurrence of each character
            return helper(n-1, str, dp, last);
        }
    };

    class Solution {
      public:
          int distinctSubseq(string &str) {
              int n = str.size();
              const int MOD = 1e9 + 7;
              vector<int> dp(n + 1, 0);    // dp[i] = number of distinct subsequences of str[0..i-1]
              vector<int> last(26, -1);    // last occurrence of each character
      
              dp[0] = 1;  // empty string
      
              for(int i = 1; i <= n; i++) {
                  char c = str[i-1];
                  dp[i] = (2LL * dp[i-1]) % MOD;
      
                  if(last[c - 'a'] != -1) {
                      int idx = last[c - 'a'];
                      dp[i] = (dp[i] - dp[idx - 1] + MOD) % MOD; // subtract duplicates
                  }
      
                  last[c - 'a'] = i;
              }
      
              return dp[n]; // number of distinct subsequences including empty string
          }
      };