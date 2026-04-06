// You are given a 0-indexed integer array nums and a target element target.

// A target index is an index i such that nums[i] == target.

// Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

 

// Example 1:

// Input: nums = [1,2,5,2,3], target = 2
// Output: [1,2]
// Explanation: After sorting, nums is [1,2,2,3,5].
// The indices where nums[i] == 2 are 1 and 2.

// Example 2:

// Input: nums = [1,2,5,2,3], target = 3
// Output: [3]
// Explanation: After sorting, nums is [1,2,2,3,5].
// The index where nums[i] == 3 is 3.

// Example 3:

// Input: nums = [1,2,5,2,3], target = 5
// Output: [4]
// Explanation: After sorting, nums is [1,2,2,3,5].
// The index where nums[i] == 5 is 4.

 

// Constraints:

//     1 <= nums.length <= 100
//     1 <= nums[i], target <= 100

class Solution {
  public:
      vector<int> targetIndices(vector<int>& nums, int target) {
          int less = 0, equal = 0;
  
          // Count elements
          for(int num : nums) {
              if(num < target) less++;
              else if(num == target) equal++;
          }
  
          vector<int> ans;
  
          // Fill indices
          for(int i = 0; i < equal; i++) {
              ans.push_back(less + i);
          }
  
          return ans;
      }
  };
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
      vector<int> targetIndices(vector<int>& nums, int target) {
          int countLess = 0;   // Count of elements < target
          int countEqual = 0;  // Count of elements == target
  
          for(int num : nums) {
              if(num < target) countLess++;
              else if(num == target) countEqual++;
          }
  
          vector<int> ans;
          for(int i = 0; i < countEqual; i++) {
              ans.push_back(countLess + i);
          }
  
          return ans;
      }
  };

// Function to return indices of target value k in sorted array
vector<int> count_el(vector<int> nums, int k) {
    vector<int> ans;

    // Step 1: Sort the array
    sort(nums.begin(), nums.end());

    // Step 2: Collect indices where value == k
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == k) {
            ans.push_back(i);  // store index in sorted array
        }
    }

    // Step 3: Return indices vector
    return ans;
}

int main() {
    int n;
    cin >> n;                 // Input size
    vector<int> nums(n);

    // Input array elements
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }  

    int k;
    cin >> k;                 // Input target value

    // Call function
    vector<int> indices = count_el(nums, k);

    // Print count
    cout << indices.size() << endl;

    // Print indices
    for(int idx : indices) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}

