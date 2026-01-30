

#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      int maxDepth(string s) {
          int currDepth = 0;
          int maxDepth = 0;
  
          for (char c : s) {
              if (c == '(') {
                  currDepth++;
                  maxDepth = max(maxDepth, currDepth);
              } else if (c == ')') {
                  currDepth--;
              }
          }
  
          return maxDepth;
      }
  };