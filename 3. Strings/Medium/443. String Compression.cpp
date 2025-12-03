#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
  public:
      int compress(vector<char>& chars) {
          int j = 0;
          int i = 0;
          int n = chars.size();
  
          while (i < n) {
              char c = chars[i];
              int cnt = 0;
  
              while (i < n && chars[i] == c) {
                  cnt++; i++;
              }
  
              chars[j++] = c;
              if (cnt > 1) {
                  string s = to_string(cnt);
                  for (char d : s) chars[j++] = d;
              }
          }
          return j;
      }
  };
  