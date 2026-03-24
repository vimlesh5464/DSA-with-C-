// Given an integer array nums of unique elements, return all possible (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

 

// Constraints:

//     1 <= nums.length <= 10
//     -10 <= nums[i] <= 10
//     All the numbers of nums are unique.

#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      void backtrack(vector<int>& nums, int index, 
                     vector<int>& subset, 
                     vector<vector<int>>& subsetsResult,
                     vector<int>& sumsResult) 
      {
          // Store current subset
          subsetsResult.push_back(subset);
  
          // Calculate and store sum of current subset
          int sum = 0;
          for (int x : subset) sum += x;
          sumsResult.push_back(sum);
  
          // Generate further subsets
          for (int i = index; i < nums.size(); i++) {
              subset.push_back(nums[i]);             
              backtrack(nums, i + 1, subset, subsetsResult, sumsResult);
              subset.pop_back();                     
          }
      }
  
      // Returns all subsets AND their sums
      pair<vector<vector<int>>, vector<int>> subsetsWithSum(vector<int>& nums) {
          vector<vector<int>> subsetsResult;
          vector<int> sumsResult;
          vector<int> subset;
  
          backtrack(nums, 0, subset, subsetsResult, sumsResult);
          return {subsetsResult, sumsResult};
      }
  };
  int main() {
    vector<int> nums = {1, 2, 3};

    Solution obj;
    auto result = obj.subsetsWithSum(nums);

    auto subsets = result.first;
    auto sums = result.second;

    cout << "Subsets with sums:\n";
    for (int i = 0; i < subsets.size(); i++) {
        cout << "{ ";
        for (int x : subsets[i]) cout << x << " ";
        cout << "}  Sum = " << sums[i] << "\n";
    }

    return 0;
}
