#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      int maxSubarraySumCircular(vector<int>& arr) {
          int totalSum = 0;
          int maxKadane = arr[0], curMax = 0;
          int minKadane = arr[0], curMin = 0;
  
          for (int x : arr) {
              curMax = max(x, curMax + x);
              maxKadane = max(maxKadane, curMax);
  
              curMin = min(x, curMin + x);
              minKadane = min(minKadane, curMin);
  
              totalSum += x;
          }
  
          // all numbers are negative
          if (maxKadane < 0)
              return maxKadane;
  
          return max(maxKadane, totalSum - minKadane);
      }
  };