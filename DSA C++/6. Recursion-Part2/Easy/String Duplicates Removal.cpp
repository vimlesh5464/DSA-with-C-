// Given a string s which may contain lowercase and uppercase characters. The task is to remove all duplicate characters from the string and find the resultant string. The order of remaining characters in the output should be same as in the original string.

// Example 1:

// Input: s = "geEksforGEeks"
// Output: "geEksforG"
// Explanation: After removing duplicate characters such as E, e, k, s, we have string as "geEksforG".

// Example 2:

// Input: s = "HaPpyNewYear"
// Output: "HaPpyNewYr"
// Explanation: After removing duplicate characters such as e, a, we have string as "HaPpyNewYr".

// Constraints:
// 1 ≤ N ≤ 106
// String contains uppercase and lowercase english letters.
#include<iostream>
using namespace std;
class Solution {
  public:
      void solve(string &s, string &ans, int i, vector<bool> &visited) {
          if(i == s.size()) return;
  
          char ch = s[i];
  
          if(!visited[ch]) {
              visited[ch] = true;
              ans += ch;
          }
  
          solve(s, ans, i + 1, visited);
      }
  
      string removeDuplicates(string &s) {
          string ans = "";
          vector<bool> visited(256, false);
  
          solve(s, ans, 0, visited);
  
          return ans;
      }
  };