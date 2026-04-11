// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.

 

// Example 1:

// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]

// Example 2:

// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15

 

// Constraints:

//     1 <= nums.length <= 3 * 104
//     nums[i] is either 0 or 1.
//     0 <= goal <= nums.length

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

//Time Complexity: O(n²), where n is the length of the array.We are using two nested loops to explore all possible subarrays. Each subarray takes O(1) time to compute the sum cumulatively, so overall O(n²) pairs are checked.

//Space Complexity: O(1), constant space .We only use integer variables to store counts and intermediate sums.
class Solution {
public:
    // Function to count number of subarrays with sum equal to goal
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Variable to store the final count of valid subarrays
        int count = 0;

        // Outer loop to fix the starting index of subarray
        for (int start = 0; start < nums.size(); ++start) {
            // Variable to store sum of current subarray
            int sum = 0;

            // Inner loop to fix the ending index of subarray
            for (int end = start; end < nums.size(); ++end) {
                // Add the current element to sum
                sum += nums[end];

                // If subarray sum equals goal, increment count
                if (sum == goal) {
                    count++;
                }
            }
        }

        // Return the total count of valid subarrays
        return count;
    }
};


//Time Complexity: O(n), where n is the size of the input array.This is because the algorithm uses the sliding window technique twice (in the two calls to atMost). Each `atMost` function runs in linear time , the left and right pointers only move forward, never backward, so the total number of operations is at most 2n.

//Space Complexity: O(1), constant extra space.Only a few integer variables are used .

class Solution {
public:
    // Function to calculate number of subarrays with sum exactly equal to goal
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Return difference between subarrays with sum at most goal and at most (goal - 1)
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    // Helper function to compute number of subarrays with sum at most k
    int atMost(vector<int>& nums, int k) {
        // If k is negative, no such subarrays exist
        if (k < 0) return 0;

        int left = 0;
        int sum = 0;
        int count = 0;

        // Traverse the array using right pointer
        for (int right = 0; right < nums.size(); right++) {
            // Add current element to sum
            sum += nums[right];

            // Shrink the window from the left if sum exceeds k
            while (sum > k) {
                sum -= nums[left];
                left++;
            }

            // Add the number of valid subarrays ending at right
            count += (right - left + 1);
        }

        return count;
    }
};

