// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

// Example 1:

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.

// Example 2:

// Input: nums = [-1,0]
// Output: [-1,0]

// Example 3:

// Input: nums = [0,1]
// Output: [1,0]

 

// Constraints:

//     2 <= nums.length <= 3 * 104
//     -231 <= nums[i] <= 231 - 1
//     Each integer in nums will appear twice, only two integers will appear once.

#include <iostream>
#include <vector>
#include<map>
 using namespace std;
// Time Complexity: O(N), where N is the size of the array.
// Traversing the array to update the Hash Map: O(N).
// Traversing the map: O(N) (in the worst case).
// Sorting the answer array: O(2*log(2)) ~ O(1).

// Hence, the overall time complexity is O(N) + O(N) + O(1) ~ O(N).

// Space Complexity: O(N), since we are using a hashmap data structure, and in the worst case (when all elements in the array are unique), it will store N key-value pairs. 

class Solution {
  public:
      vector<int> singleNumber(vector<int>& nums) {
          map<int, int> map;
          vector<int> ans;
          int n = nums.size();
  
          for (int i = 0; i < n; i++) {
              map[nums[i]]++;
          }
  
          for (auto it : map) {
              if (it.second == 1) {
                  ans.push_back(it.first);
              }
          }
          return ans;
      }
  };

//   Time Complexity: O(N), traversing the array twice results in O(2*N) time complexity.

// Space Complexity: O(1), using a couple of variables, i.e., constant space. 
class Solution {
  public:
      vector<int> singleNumber(vector<int>& nums) {
          // Variable to store size of array
          int n = nums.size();
  
          // Variable to store XOR of all elements
          long XOR = 0;
  
          // Traverse the array
          for (int i = 0; i < n; i++) {
  
              // Update the XOR
              XOR = XOR ^ nums[i];
          }
  
          /* Variable to get the rightmost
          set bit in overall XOR */
          int rightmost = (XOR & (XOR - 1)) ^ XOR;
  
          /* Variables to stores XOR of
          elements in bucket 1 and 2 */
          int XOR1 = 0, XOR2 = 0;
  
          // Traverse the array
          for (int i = 0; i < n; i++) {
  
              /* Divide the numbers among bucket 1
               and 2 based on rightmost set bit */
              if (nums[i] & rightmost) {
                  XOR1 = XOR1 ^ nums[i];
              } else {
                  XOR2 = XOR2 ^ nums[i];
              }
          }
  
          // Return the result in sorted order
          if (XOR1 < XOR2)
              return {XOR1, XOR2};
          return {XOR2, XOR1};
      }
  };