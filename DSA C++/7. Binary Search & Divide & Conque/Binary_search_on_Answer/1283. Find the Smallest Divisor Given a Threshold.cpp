// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

// Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

// The test cases are generated so that there will be an answer.

 

// Example 1:

// Input: nums = [1,2,5,9], threshold = 6
// Output: 5
// Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
// If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 

// Example 2:

// Input: nums = [44,22,33,11,1], threshold = 5
// Output: 44

 

// Constraints:

//     1 <= nums.length <= 5 * 104
//     1 <= nums[i] <= 106
//     nums.length <= threshold <= 106


#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    // Function to find the smallest divisor such that
    // the sum of ceil(arr[i] / d) over all i <= limit
    int smallestDivisor(vector<int>& arr, int limit) {
        int n = arr.size(); // Size of the array

        // Find the maximum element in the array
        int maxi = *max_element(arr.begin(), arr.end());

        // Try every possible divisor from 1 to maxi
        for (int d = 1; d <= maxi; d++) {
            int sum = 0;

            // For each element, compute ceil(arr[i] / d) and add to sum
            for (int i = 0; i < n; i++) {
                sum += ceil((double)(arr[i]) / (double)(d));
            }

            // If the total sum is within the limit, return this divisor
            if (sum <= limit) {
                return d;
            }
        }

        // If no valid divisor is found, return -1
        return -1;
    }
};


class SmallestDivisorFinder {
public:
    // Helper function to calculate sum of division results
    int sumByD(vector<int>& arr, int div) {
        int sum = 0;
        for (int num : arr) {
            sum += ceil((double)num / div);
        }
        return sum;
    }

    // Function to find the smallest divisor
    int smallestDivisor(vector<int>& arr, int limit) {
        if (arr.size() > limit) return -1;

        int low = 1;
        int high = *max_element(arr.begin(), arr.end());

        // Binary search to find smallest divisor
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumByD(arr, mid) <= limit) {
                high = mid - 1;  // Try smaller divisor
            } else {
                low = mid + 1;   // Try larger divisor
            }
        }

        return low;
    }
};



