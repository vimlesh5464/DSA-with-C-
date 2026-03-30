// Given an integer array nums, find a that has the largest product, and return 
//the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// Note that the product of an array with a single element is the value of that 
//element.

 

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

 

// Constraints:

//     1 <= nums.length <= 2 * 104
//     -10 <= nums[i] <= 10
//     The product of any subarray of nums is guaranteed to fit in a 32-bit integer.

 
#include <iostream>
#include<vector>
using namespace std;

// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            // If current number is negative, swap max and min
            if (curr < 0) {
                swap(maxSoFar, minSoFar);
            }

            maxSoFar = max(curr, curr * maxSoFar);
            minSoFar = min(curr, curr * minSoFar);

            result = max(result, maxSoFar);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum product subarray = " << sol.maxProduct(nums) << endl;

    vector<int> nums2 = {-2, 0, -1};
    cout << "Maximum product subarray = " << sol.maxProduct(nums2) << endl;

    return 0;
}
