// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

 

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

// Example 2:

// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There are no odd numbers in the array.

// Example 3:

// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16

 

// Constraints:

//     1 <= nums.length <= 50000
//     1 <= nums[i] <= 10^5
//     1 <= k <= nums.length
#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(N2) ,We use two nested loops to check all possible subarrays. For each subarray, we count the number of odd elements. The outer loop runs from index 0 to N-1, and the inner loop also runs up to N in the worst case. So total iterations can be approximately N * N = O(N2).

// Space Complexity: O(1), No extra space used.
class Solution {
public:
    // Function to count subarrays with exactly k odd numbers
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Initialize counter for total nice subarrays
        int count = 0;

        // Loop over all starting indices
        for (int start = 0; start < nums.size(); start++) {
            // Track number of odd elements in current subarray
            int oddCount = 0;

            // Loop over ending indices starting from 'start'
            for (int end = start; end < nums.size(); end++) {
                // Check if current number is odd
                if (nums[end] % 2 != 0)
                    oddCount++;

                // If odd count exceeds k, break (not nice)
                if (oddCount > k) break;

                // If odd count is exactly k, count this subarray
                if (oddCount == k)
                    count++;
            }
        }

        // Return total nice subarrays
        return count;
    }
};

class Solution {
public:
    // function to count subarrays with at most k odd numbers
    int countAtMost(vector<int>& nums, int k) {
        // Initialize variables
        int left = 0, res = 0;

        // Traverse through the array
        for (int right = 0; right < nums.size(); right++) {
            // If current number is odd, reduce k
            if (nums[right] % 2 != 0)
                k--;

            // Shrink the window until k is valid
            while (k < 0) {
                if (nums[left] % 2 != 0)
                    k++;
                left++;
            }

            // Add valid subarrays ending at right
            res += (right - left + 1);
        }

        // Return the count of valid subarrays
        return res;
    }

    // Main function to get number of subarrays with exactly k odd numbers
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << sol.numberOfSubarrays(nums, k) << endl;
    return 0;
}

