#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      bool isTrionic(vector<int>& nums) {
          int n = nums.size();
          if (n < 3) return false;
  
          int i = 0;
  
          // 1️⃣ strictly increasing
          while (i + 1 < n && nums[i] < nums[i + 1]) {
              i++;
          }
          if (i == 0) return false;   // no increasing part
  
          // 2️⃣ strictly decreasing
          int j = i;
          while (j + 1 < n && nums[j] > nums[j + 1]) {
              j++;
          }
          if (j == i) return false;   // no decreasing part
  
          // 3️⃣ strictly increasing again
          int k = j;
          while (k + 1 < n && nums[k] < nums[k + 1]) {
              k++;
          }
          if (k == j) return false;   // no final increasing part
  
          // must consume whole array
          return k == n - 1;
      }
  };
  