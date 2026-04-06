// Given an array of distinct integers nums and a target integer target, 
//return the number of possible combinations that add up to target.

// The test cases are generated so that the answer can fit in a 32-bit integer.

 

// Example 1:

// Input: nums = [1,2,3], target = 4
// Output: 7
// Explanation:
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// Note that different sequences are counted as different combinations.

// Example 2:

// Input: nums = [9], target = 3
// Output: 0

 

// Constraints:

//     1 <= nums.length <= 200
//     1 <= nums[i] <= 1000
//     All the elements of nums are unique.
//     1 <= target <= 1000

#include<iostream>
#include<vector>
using namespace std;
int combi(vector<int>& nums, int target){
  if(target == 0) return 1;
  if(target < 0) return 0;

  int count = 0;

  for(int i = 0; i < nums.size(); i++){
      count += combi(nums, target - nums[i]);
  }

  return count;
}
class Solution {
  public:
      int solve(vector<int>& nums, int target, vector<int>& dp) {
          if(target == 0) return 1;
          if(target < 0) return 0;
  
          // Memoization check
          if(dp[target] != -1) return dp[target];
  
          int count = 0;
  
          for(int i = 0; i < nums.size(); i++){
              count += solve(nums, target - nums[i], dp);
          }
  
          return dp[target] = count;
      }
  
      int combinationSum4(vector<int>& nums, int target) {
          vector<int> dp(target + 1, -1);
          return solve(nums, target, dp);
      }
  };


  
void combi(vector<int>& nums, int target, vector<int>& path) {
  // Base case
  if(target == 0) {
      // print one valid combination
      for(int x : path) cout << x << " ";
      cout << endl;
      return;
  }

  if(target < 0) return;

  // Try all numbers (order matters)
  for(int i = 0; i < nums.size(); i++) {
      path.push_back(nums[i]);              // choose
      combi(nums, target - nums[i], path); // explore
      path.pop_back();                      // backtrack
  }
}
int main(){
  vector<int> subset;
  int target = 2;
  vector<int> nums={1,2,3};
  vector<vector<int>> ans;
  int count = combi(nums,target);
  cout<< "count: "<<count<<endl;
  for(int i = 0; i < ans.size(); i++){
    for(int j = 0; j < ans[i].size(); j++){
      cout<<ans[i][j];
    }
    cout<<endl;
  }
  return 0;
}