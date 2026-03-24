#include<iostream>
using namespace std;
#include<vector>
class Solution {
  public:
      int binaryGap(int n) {
          int lastPos = -1;
          int maxDist = 0;
          int pos = 0;
  
          while(n > 0) {
              if(n & 1) {  // if current bit is 1
                  if(lastPos != -1) {
                      maxDist = max(maxDist, pos - lastPos);
                  }
                  lastPos = pos;
              }
              n >>= 1;  // right shift
              pos++;
          }
  
          return maxDist;
      }
  };