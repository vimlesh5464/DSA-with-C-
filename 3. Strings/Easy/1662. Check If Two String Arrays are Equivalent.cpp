#include<iostream>
#include<vector>
using namespace std;

// Time	O(N + M)
// Space	O(N + M)
class Solution {
  public:
      bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
          string s1,s2;
          for (int i = 0; i < word1.size(); i++) {
              s1 += word1[i];
          }
  
          for (int i = 0; i < word2.size(); i++) {
              s2 += word2[i];
          }
          int n = s1.size();
          int m = s2.size();
          if(n!=m){
              return false;
          }
          for(int i = 0; i < n; i++){
              if(s1[i]!=s2[i]){
                  return false;
              }
          }
          return true;
      }
  };

//   Time	O(N + M)
// Space	O(1)
class Solution {
  public:
      bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
          int i = 0, j = 0, p1 = 0, p2 = 0;
  
          while (i < word1.size() && j < word2.size()) {
              if (word1[i][p1] != word2[j][p2]) {
                  return false;
              }
  
              p1++;
              p2++;
  
              if (p1 == word1[i].size()) {
                  i++;
                  p1 = 0;
              }
  
              if (p2 == word2[j].size()) {
                  j++;
                  p2 = 0;
              }
          }
  
          return i == word1.size() && j == word2.size();
      }
  };
  