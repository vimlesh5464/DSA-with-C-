#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
  public:
      void solve(string &s, int idx, string &current, vector<string> &ans) {
  
          // If full string processed → push answer
          if (idx == s.size()) {
              ans.push_back(current);
              return;
          }
  
          char c = s[idx];
  
          // If digit → only one choice
          if (isdigit(c)) {
              current.push_back(c);
              solve(s, idx + 1, current, ans);
              current.pop_back();
          } 
          else {
              // Lowercase branch
              current.push_back(tolower(c));
              solve(s, idx + 1, current, ans);
              current.pop_back();
  
              // Uppercase branch
              current.push_back(toupper(c));
              solve(s, idx + 1, current, ans);
              current.pop_back();
          }
      }
  
      vector<string> letterCasePermutation(string s) {
          vector<string> ans;
          string current = "";
          solve(s, 0, current, ans);
          return ans;
      }
  };
  