
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

 

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

// Example 2:

// Input: nums = [0]
// Output: [0]

 

// Constraints:

//     1 <= nums.length <= 104
//     -231 <= nums[i] <= 231 - 1

 
// Follow up: Could you minimize the total number of operations done?



#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      void moveZeroes(vector<int>& nums) {
          int n = nums.size();
          vector<int> ans;
          for(int i = 0; i < n; i++){
              if(nums[i]!=0){
                  ans.push_back(nums[i]);
              }
          }
          int n2 = ans.size();
          for(int i = 0; i < n2; i++){
              nums[i] = ans[i];
          }
          for(int i = n2; i < n; i++){
              nums[i] = 0;
          }
      }
  };