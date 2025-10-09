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
