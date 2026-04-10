// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

 

// Constraints:

//     2 <= nums.length <= 104
//     -109 <= nums[i] <= 109
//     -109 <= target <= 109
//     Only one valid answer exists.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
  public:
      vector<int> twoSum(vector<int>& nums, int target) {
          int n = nums.size();
  
          for (int i = 0; i < n; i++) {
              for (int j = i + 1; j < n; j++) {
                  if (nums[i] + nums[j] == target) {
                      return {i, j};
                  }
              }
          }
          return {};
      }
  };

  class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<pair<int,int>> arr;
    
            for (int i = 0; i < nums.size(); i++) {
                arr.push_back({nums[i], i});
            }
    
            sort(arr.begin(), arr.end());
    
            int left = 0, right = arr.size() - 1;
    
            while (left < right) {
                int sum = arr[left].first + arr[right].first;
    
                if (sum == target) {
                    return {arr[left].second, arr[right].second};
                }
                else if (sum < target) left++;
                else right--;
            }
    
            return {};
        }
    };


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};