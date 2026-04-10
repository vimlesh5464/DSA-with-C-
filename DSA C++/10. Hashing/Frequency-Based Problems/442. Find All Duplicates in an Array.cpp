// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

 

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]

// Example 2:

// Input: nums = [1,1,2]
// Output: [1]

// Example 3:

// Input: nums = [1]
// Output: []

 

// Constraints:

//     n == nums.length
//     1 <= n <= 105
//     1 <= nums[i] <= n
//     Each element in nums appears once or twice.


#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
  vector<int> result;

  for (int i = 0; i < nums.size(); i++) {
      int count = 0;

      for (int j = 0; j < nums.size(); j++) {
          if (nums[i] == nums[j]) count++;
      }

      if (count == 2) {
          if (find(result.begin(), result.end(), nums[i]) == result.end())
              result.push_back(nums[i]);
      }
  }

  return result;
}

class Solution {
  public:
      vector<int> findDuplicates(vector<int>& nums) {
          // Step 1: Create an empty unordered map to store
      // element frequencies
      int n = nums.size();
      unordered_map<int, int> freqMap;
      vector<int> result;
  
      // Step 2: Iterate through the array and count
      // element frequencies
      for (int i = 0; i < n; i++) {
          freqMap[nums[i]]++;
      }
  
      // Step 3: Iterate through the hashmap to find duplicates
      for (auto &entry : freqMap) {
          if (entry.second > 1) {
              result.push_back(entry.first);
          }
      }
  
    
      // Step 6: Return the result vector containing
      // duplicate elements or -1
      return result;
      }
  };
vector<int> findDuplicates(vector<int>& nums) {
  vector<int> result;

  for (int i = 0; i < nums.size(); i++) {
      int index = abs(nums[i]) - 1;

      if (nums[index] < 0) {
          // already visited → duplicate
          result.push_back(abs(nums[i]));
      } else {
          // mark as visited
          nums[index] = -nums[index];
      }
  }

  return result;
}