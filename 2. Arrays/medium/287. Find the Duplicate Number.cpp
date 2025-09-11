#include <iostream>
#include<unordered_set>
#include<vector>
using namespace std;
//Approach 1: Using HashSet (Extra Space)Idea:
// Traverse the array and add each element to a set.
// If an element already exists in the set, that’s the duplicate.

class Solution {
  public:
      int findDuplicate(vector<int>& nums) {
          unordered_set<int> seen;          // Step 1: Create a set to store seen numbers
          
          for (int num : nums) {            // Step 2: Traverse all numbers in the array
              if (seen.count(num))          // Step 3: If number already exists in the set
                  return num;               // → it is the duplicate, return it
              seen.insert(num);             // Step 4: Otherwise, add it to the set
          }
  
          return -1;                        // Step 5: If no duplicate found (won’t happen in this problem)
      }
  };
  
  // Approach 2: Sorting (Modifies Array)
  // Sort the array, then check consecutive elements.
  // Duplicate will appear consecutively.
  // Time Complexity: O(n log n)
  // Space Complexity: O(1) or O(n) depending on sorting implementation.
  class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            sort(nums.begin(), nums.end()); // Step 1: Sort the array
    
            for (int i = 1; i < nums.size(); i++) { // Step 2: Traverse and check consecutive elements
                if (nums[i] == nums[i-1]) {
                    return nums[i]; // Step 3: Found the duplicate
                }
            }
    
            return -1; // Not reached if a duplicate exists
        }
    };


// Approach 3: Floyd’s Tortoise and Hare (Cycle Detection, Optimal)Idea:
// Treat the array as a linked list where nums[i] points to nums[nums[i]].
// Use slow and fast pointers to detect the cycle.
// The entry point of the cycle is the duplicate number.
// Time Complexity: O(n)
// Space Complexity: O(1) → no extra space
class Solution {
  public:
      int findDuplicate(vector<int>& nums) {
          int slow = nums[0];
          int fast = nums[0];
  
          // Step 1: Detect cycle
          do {
              slow = nums[slow];
              fast = nums[nums[fast]];
          } while(slow != fast);
  
          // Step 2: Find entry point of cycle
          slow = nums[0];
          while(slow != fast) {
              slow = nums[slow];
              fast = nums[fast];
          }
  
          return slow;
      }
  };
  

int main() {
    Solution s;
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << "Duplicate number is: " << s.findDuplicate(nums) << endl;
    return 0;
}
