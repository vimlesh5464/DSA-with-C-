#include <iostream>
#include<vector>
using namespace std;


class Solution {
  public:
      int helper(int index, int target, vector<int>& arr) {
          // Base case
          if (index == 0) {
              if (target == 0 && arr[0] == 0) return 2; // either take or not take zero
              if (target == 0 || target == arr[0]) return 1;
              return 0;
          }
  
          // Choice 1: exclude current element
          int notTake = helper(index - 1, target, arr);
  
          // Choice 2: include current element (if possible)
          int take = 0;
          take = helper(index - 1, target - arr[index], arr);
  
          return take + notTake;
      }
  
      int countSubsets(vector<int>& arr, int k) {
          int n = arr.size();
          return helper(n - 1, k, arr);
      }
  };
  