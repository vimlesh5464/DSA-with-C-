// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

// Example 1:

// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation: 
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.

// Example 2:

// Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
// Output: "aaaaaaaa"

 

// Constraints:

//     1 <= str1.length, str2.length <= 1000
//     str1 and str2 consist of lowercase English letters.

 
#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
  public:
      string scs(string &str1, string &str2, int i, int j) {
          // Base cases
          if(i == str1.size()) return str2.substr(j);
          if(j == str2.size()) return str1.substr(i);
  
          // If characters match
          if(str1[i] == str2[j]) {
              return str1[i] + scs(str1, str2, i + 1, j + 1);
          } else {
              // Two options, take min length
              string option1 = str1[i] + scs(str1, str2, i + 1, j);
              string option2 = str2[j] + scs(str1, str2, i, j + 1);
  
              return (option1.size() < option2.size()) ? option1 : option2;
          }
      }
  
      string shortestCommonSupersequence(string str1, string str2) {
          return scs(str1, str2, 0, 0);
      }
  };

  class Solution {
    public:
       
    
        string scs(string &str1, string &str2, int i, int j,vector<vector<string>>&dp) {
            if(i == str1.size()) return str2.substr(j);
            if(j == str2.size()) return str1.substr(i);
    
            if(!dp[i][j].empty()) return dp[i][j];
    
            if(str1[i] == str2[j]) {
                dp[i][j] = str1[i] + scs(str1, str2, i+1, j+1,dp);
            } else {
                string option1 = str1[i] + scs(str1, str2, i+1, j,dp);
                string option2 = str2[j] + scs(str1, str2, i, j+1,dp);
    
                dp[i][j] = (option1.size() < option2.size()) ? option1 : option2;
            }
            return dp[i][j];
        }
    
        string shortestCommonSupersequence(string str1, string str2) {
            int n = str1.size(), m = str2.size();
            vector<vector<string>>dp(n, vector<string>(m, ""));
            return scs(str1, str2, 0, 0,dp);
        }
    };
    
class Solution {
  public:
      string shortestCommonSupersequence(string s1, string s2) {
          // Get the lengths of the two strings
          int n = s1.size();
          int m = s2.size();
  
          // Create a 2D DP table to store lengths of LCS
          vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  
          // Initialize base cases: when either string is empty
          for (int i = 0; i <= n; i++) {
              dp[i][0] = 0;
          }
          for (int i = 0; i <= m; i++) {
              dp[0][i] = 0;
          }
  
          // Fill the DP table using bottom-up approach
          for (int ind1 = 1; ind1 <= n; ind1++) {
              for (int ind2 = 1; ind2 <= m; ind2++) {
  
                  // If characters match, take diagonal + 1
                  if (s1[ind1 - 1] == s2[ind2 - 1])
                      dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
  
                  // Otherwise, take max from left or top
                  else
                      dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
              }
          }
  
          // Start from bottom-right of the DP table to build the supersequence
          int i = n;
          int j = m;
          string ans = "";
  
          // Traverse the table in reverse to find the supersequence
          while (i > 0 && j > 0) {
  
              // If characters are equal, include it once
              if (s1[i - 1] == s2[j - 1]) {
                  ans += s1[i - 1];
                  i--;
                  j--;
              }
  
              // Move in the direction of greater value
              else if (dp[i - 1][j] > dp[i][j - 1]) {
                  ans += s1[i - 1];
                  i--;
              } else {
                  ans += s2[j - 1];
                  j--;
              }
          }
  
          // If any characters are left in s1, add them
          while (i > 0) {
              ans += s1[i - 1];
              i--;
          }
  
          // If any characters are left in s2, add them
          while (j > 0) {
              ans += s2[j - 1];
              j--;
          }
  
          // Since we added characters in reverse order, reverse the result
          reverse(ans.begin(), ans.end());
  
          // Return the final shortest supersequence
          return ans;
      }
  };