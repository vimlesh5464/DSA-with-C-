// Find all valid combinations of k numbers that sum up to n such that the following 
//conditions are true:

//     Only numbers 1 through 9 are used.
//     Each number is used at most once.

// Return a list of all possible valid combinations. The list must not contain the 
//same combination twice, and the combinations may be returned in any order.

 

// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.

// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.

// Example 3:

// Input: k = 4, n = 1
// Output: []
// Explanation: There are no valid combinations.
// Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

 

// Constraints:

//     2 <= k <= 9
//     1 <= n <= 60

 
#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
  // Recursive function to find combinations
      void func(int sum, int last, vector<int> &nums, int k, vector<vector<int>> &ans) {
          // If the sum is zero and the number of elements is k
          if(sum == 0 && nums.size() == k) {
              // Add the current combination to the answer
              ans.push_back(nums);
              return; 
          }
          // If the sum is less than or equal to zero or the number of elements exceeds k
          if(sum <= 0 || nums.size() > k) return; 
  
          // Iterate from the last number to 9
          for(int i = last; i <= 9; i++) {
              // If the current number is less than or equal to the sum
              if(i <= sum) {
                  // Add the number to the current combination
                  nums.push_back(i); 
                  // Recursive call with updated sum and next number
                  func(sum - i, i + 1, nums, k, ans); 
                  // Remove the last number to backtrack
                  nums.pop_back(); 
              } else {
                  // If the number is greater than the sum, break the loop
                  break;
              }
          }
      } 
      vector<vector<int>> combinationSum3(int k, int n) {
          vector<vector<int>> ans; 
          vector<int> nums; 
          // Call the recursive function with initial parameters
          func(n, 1, nums, k, ans);
          return ans; 
      }
  };