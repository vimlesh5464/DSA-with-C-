// You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.

// Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

// Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

 

// Example 1:

// Input: nums = [10,1,2,7,1,3], p = 2
// Output: 1
// Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
// The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.

// Example 2:

// Input: nums = [4,2,1,2], p = 1
// Output: 0
// Explanation: Let the indices 1 and 3 form a pair. The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.

 

// Constraints:

//     1 <= nums.length <= 105
//     0 <= nums[i] <= 109
//     0 <= p <= (nums.length)/2

 
#include <iostream>     
#include<vector>
using namespace std;

class Solution {
public:
    // Helper function: checks if we can form at least 'p' pairs 
    // with difference <= maxDiff
    bool isValid(vector<int>& nums, int p, int maxDiff) {
        int count = 0;
        for (int i = 1; i < nums.size();) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i += 2; // use both nums[i-1] and nums[i]
            } else {
                i += 1; // skip one
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back() - nums.front();
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValid(nums, p, mid)) {
                result = mid;      // valid → try smaller maxDiff
                high = mid - 1;
            } else {
                low = mid + 1;     // not valid → need bigger maxDiff
            }
        }

        return result;
    }
};

// Driver code for testing
int main() {
    Solution sol;
    
    vector<int> nums1 = {10, 1, 2, 7, 1, 3};
    int p1 = 2;
    cout << sol.minimizeMax(nums1, p1) << endl; // Output: 1

    vector<int> nums2 = {4, 2, 1, 2};
    int p2 = 1;
    cout << sol.minimizeMax(nums2, p2) << endl; // Output: 0

    return 0;
}
