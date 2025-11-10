#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
  bool isPalindrome(string &s, int start, int end) {
          // Loop while start < end
          while (start < end) {
              // If mismatch, not a palindrome
              if (s[start] != s[end]) return false;
              // Move pointers inward
              start++;
              end--;
          }
          // All characters matched
          return true;
      }
  void helper(string&s,int index,vector<string>&path,vector<vector<string>>& ans){
      if(index==s.size()){
          if(!path.empty()){
              ans.push_back(path);
          }
          return;
      }
      for(int i = index; i < s.size(); i++){
          if(isPalindrome(s,index,i)){
              path.push_back(s.substr(index, i - index + 1));
              helper(s,i+1,path,ans);
              path.pop_back();
          }
      }
  }
      vector<vector<string>> partition(string s) {
          vector<vector<string>> ans;
          vector<string> path;
          helper(s,0,path,ans);
          return ans;
      }
  };