// Given a sorted array of distinct integers and a target value, 
//return the index if the target is found. If not, 
//return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2

// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1

// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4

 

// Constraints:

//     1 <= nums.length <= 104
//     -104 <= nums[i] <= 104
//     nums contains distinct values sorted in ascending order.
//     -104 <= target <= 104

 

#include <iostream>     
#include<vector>
using namespace std;

class Solution {
  public:
      int searchInsert(vector<int>& nums, int target) {
          for(int i = 0; i < nums.size(); i++) {
              if(nums[i] >= target) {
                  return i;
              }
          }
          // if target is greater than all elements
          return nums.size();
      }
  };

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;  // Prevents overflow

            if (nums[mid] == target) {
                return mid; // target found
            } 
            else if (nums[mid] > target) {
                high = mid - 1; // search left half
            } 
            else {
                low = mid + 1; // search right half
            }
        }

        // If not found, 'low' is the correct insert position
        return low;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    int result = sol.searchInsert(nums, target);
    cout << "Insert position of " << target << " is: " << result << endl;

    target = 2;
    result = sol.searchInsert(nums, target);
    cout << "Insert position of " << target << " is: " << result << endl;

    target = 7;
    result = sol.searchInsert(nums, target);
    cout << "Insert position of " << target << " is: " << result << endl;

    target = 0;
    result = sol.searchInsert(nums, target);
    cout << "Insert position of " << target << " is: " << result << endl;

    return 0;
}
