#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      int longestBalanced(string s) {
          int n = s.size();
          int maxLen = 0;
  
          for(int i = 0; i < n; i++) {
              vector<int> freq(26, 0); // frequency of 'a' to 'z'
              for(int j = i; j < n; j++) {
                  freq[s[j] - 'a']++;
  
                  int count = 0; // value of non-zero frequency
                  bool balanced = true;
                  for(int f : freq) {
                      if(f != 0) {
                          if(count == 0) count = f;
                          else if(f != count) {
                              balanced = false;
                              break;
                          }
                      }
                  }
  
                  if(balanced) maxLen = max(maxLen, j - i + 1);
              }
          }
  
          return maxLen;
      }
  };