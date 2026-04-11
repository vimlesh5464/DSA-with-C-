// Given an unsorted integer array nums. Return the smallest positive integer that 
//is not present in nums.

// You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

// Example 1:

// Input: nums = [1,2,0]
// Output: 3
// Explanation: The numbers in the range [1,2] are all in the array.

// Example 2:

// Input: nums = [3,4,-1,1]
// Output: 2
// Explanation: 1 is in the array but 2 is missing.

// Example 3:

// Input: nums = [7,8,9,11,12]
// Output: 1
// Explanation: The smallest positive integer 1 is missing.

 

// Constraints:

//     1 <= nums.length <= 105
//     -231 <= nums[i] <= 231 - 1

 
#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Step 1: Sort the array
    int smallest = 1;               // Step 2: Start checking from 1

    for (int num : nums) {
        if (num == smallest) {
            smallest++; // Found current smallest, move to next
        }
    }

    return smallest; // Step 3: Return the first missing positive
}

int firstMissingPositive(vector<int>& nums) {
  unordered_set<int> s;

  // Step 1: Insert all positive numbers into the hash set
  for (int num : nums) {
      if (num > 0) s.insert(num);
  }

  // Step 2: Find the first missing positive
  int smallest = 1;
  while (true) {
      if (s.find(smallest) == s.end()) {
          return smallest; // Not found → missing positive
      }
      smallest++;
  }
}


class Solution {
  public:
      int firstMissingPositive(vector<int>& nums) {
          int n = nums.size();
          bool contains = false;
  
          // Step 1: Check if 1 exists
          for (int i = 0; i < n; i++) {
              if (nums[i] == 1) {
                  contains = true;
                  break;
              }
          }
          if (!contains) return 1;
  
          // Step 2: Replace invalid numbers with 1
          for (int i = 0; i < n; i++) {
              if (nums[i] <= 0 || nums[i] > n) {
                  nums[i] = 1;
              }
          }
  
          // Step 3: Use index marking technique
          for (int i = 0; i < n; i++) {
              int a = abs(nums[i]);
              if (a == n)
                  nums[0] = -abs(nums[0]);
              else
                  nums[a] = -abs(nums[a]);
          }
  
          // Step 4: Find missing positive
          for (int i = 1; i < n; i++) {
              if (nums[i] > 0)
                  return i;
          }
  
          if (nums[0] > 0)
              return n;
  
          return n + 1;
      }
  };
  
int main() {
    vector<int> nums = {3, 4, -1, 1};
    cout << firstMissingPositive(nums); // Output: 2
    return 0;
}
