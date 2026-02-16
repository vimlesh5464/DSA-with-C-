
#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      vector<int> minBitwiseArray(vector<int>& nums) {
          vector<int> ans;
  
          for (int n : nums) {
              if (n % 2 == 0) {
                  ans.push_back(-1);
                  continue;
              }
  
              // Step 2: Find smallest x
              for (int x = 0; x < n; x++) {
                  if ((x | (x + 1)) == n) {
                      ans.push_back(x);
                      break;
                  }
              }
          }
  
          return ans;
      }
  };