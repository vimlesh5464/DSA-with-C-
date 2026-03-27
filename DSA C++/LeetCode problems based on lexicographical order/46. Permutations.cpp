
// Given an array nums of distinct integers, return all the possible . You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:

// Input: nums = [1]
// Output: [[1]]

 

// Constraints:

//     1 <= nums.length <= 6
//     -10 <= nums[i] <= 10
//     All the integers of nums are unique.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
  void get(vector<int>& nums, int ind, vector<vector<int>> &result){
      if(ind==nums.size()){
          result.push_back({nums});
          return;
      }
      for(int i = ind; i < nums.size(); i++){
          swap(nums[ind], nums[i]);
          get(nums, ind+1, result);
          swap(nums[ind], nums[i]);
      }
  }
      vector<vector<int>> permute(vector<int>& nums) {
          vector<vector<int>> result;
          get(nums, 0, result);
          return result;
      }
  };