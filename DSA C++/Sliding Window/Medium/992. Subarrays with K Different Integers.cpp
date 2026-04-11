// Given an integer array nums and an integer k, return the number of good subarrays of nums.

// A good array is an array where the number of different integers in that array is exactly k.

//     For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.

// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

// Example 2:

// Input: nums = [1,2,1,3,4], k = 3
// Output: 3
// Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

 

// Constraints:

//     1 <= nums.length <= 2 * 104
//     1 <= nums[i], k <= nums.length
#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

// Time Complexity:O(N²*K) ,We check all possible subarrays by iterating over all start
// and end indices. For each subarray, we count the number of distinct integers using a
// HashSet or frequency map, which can take up to O(K) time per check. So overall it 
//becomes O(N²*K) where N is the size of the array and K is the number of unique 
//elements allowed.

// Space Complexity:O(K) ,For each subarray, we maintain a HashSet or HashMap to store 
//the distinct elements in it. In the worst case, this set can grow to size K.
class Solution {
  public:
      int subarraysWithKDistinct(vector<int>& nums, int k) {
          // Get the size of the array
          int n = nums.size();
  
          // Variable to store the final result
          int count = 0;
  
          // Loop through all possible starting indices
          for (int i = 0; i < n; i++) {
  
              // Map to keep track of frequency of elements
              unordered_map<int, int> freq;
  
              // Loop through all possible ending indices
              for (int j = i; j < n; j++) {
  
                  // Increment frequency of current element
                  freq[nums[j]]++;
  
                  // If the number of distinct integers equals k, increment count
                  if (freq.size() == k)
                      count++;
  
                  // If it exceeds k, break out
                  if (freq.size() > k)
                      break;
              }
          }
  
          // Return the result
          return count;
      }
  };

  //Time Complexity:O(N) ,where n is the length of the array. Both calls to atMostK() are 
  //linear.

//Space Complexity:O(K) ,where k is the number of distinct elements in the current window. 
//We use a hash map to store frequency counts, which in the worst case could grow to 
//the number of unique elements in the array.
  class Solution {
    public:
     // Helper function to count subarrays with at most K distinct integers
        int atMostK(vector<int>& nums, int K) {
            unordered_map<int, int> freq;
            int left = 0, count = 0;
    
            // Traverse the array with right pointer
            for (int right = 0; right < nums.size(); right++) {
                // If it's a new unique element, decrease K
                if (freq[nums[right]] == 0) {
                    K--;
                }
    
                // Increment frequency of current element
                freq[nums[right]]++;
    
                // Shrink the window if distinct count > K
                while (K < 0) {
                    freq[nums[left]]--;
                    if (freq[nums[left]] == 0) {
                        K++;
                    }
                    left++;
                }
    
                // Count all subarrays ending at current right
                count += (right - left + 1);
            }
    
            return count;
        }
    
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            return atMostK(nums, k) - atMostK(nums, k - 1);
        }
    };