// A conveyor belt has packages that must be shipped from one port to another within days days.

// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 

// Example 1:

// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// Output: 15
// Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
// 1st day: 1, 2, 3, 4, 5
// 2nd day: 6, 7
// 3rd day: 8
// 4th day: 9
// 5th day: 10

// Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

// Example 2:

// Input: weights = [3,2,2,4,1,4], days = 3
// Output: 6
// Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
// 1st day: 3, 2
// 2nd day: 2, 4
// 3rd day: 1, 4

// Example 3:

// Input: weights = [1,2,3,1,1], days = 4
// Output: 3
// Explanation:
// 1st day: 1
// 2nd day: 2
// 3rd day: 3
// 4th day: 1, 1

 

// Constraints:

//     1 <= days <= weights.length <= 5 * 104
//     1 <= weights[i] <= 500

#include<iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    // Function to check how many days needed for given capacity
    int daysNeeded(vector<int>& weights, int capacity) {
        // Initialize day count to 1
        int days = 1;
        // Current load for the day
        int currentLoad = 0;

        // Iterate over all package weights
        for (int w : weights) {
            // If adding weight exceeds capacity
            if (currentLoad + w > capacity) {
                // Increase day count and reset load
                days++;
                currentLoad = w;
            } else {
                // Otherwise, add weight to current load
                currentLoad += w;
            }
        }
        // Return total days needed
        return days;
    }

    // Function to find minimum ship capacity to ship in d days
    int shipWithinDays(vector<int>& weights, int d) {
        // Find maximum weight as minimum capacity
        int left = *max_element(weights.begin(), weights.end());
        // Find total sum as maximum capacity
        int right = accumulate(weights.begin(), weights.end(), 0);

        // Iterate from minimum to maximum capacity
        for (int capacity = left; capacity <= right; capacity++) {
            // Calculate days needed for current capacity
            int needed = daysNeeded(weights, capacity);
            // If days needed are less than or equal to d, return capacity
            if (needed <= d) {
                return capacity;
            }
        }
        // Should never reach here given constraints
        return right;
    }
};


class Solution {
public:
    // Function to calculate how many days are needed to ship packages with given capacity
    int daysNeeded(vector<int>& weights, int capacity) {
        // Initialize count of days to 1 (start with day one)
        int days = 1;

        // Variable to track the current load on the ship for a day
        int currentLoad = 0;

        // Loop through each package weight in the array
        for (int w : weights) {
            // Check if adding current package exceeds ship capacity for the day
            if (currentLoad + w > capacity) {
                // Need a new day to ship this package, so increment day count
                days++;

                // Start new day's load with current package weight
                currentLoad = w;
            } else {
                // If capacity not exceeded, add current package weight to the day's load
                currentLoad += w;
            }
        }

        // Return total number of days needed with this capacity
        return days;
    }

    // Main function to find minimum capacity to ship all packages within d days
    int shipWithinDays(vector<int>& weights, int d) {
        // Find the maximum package weight as the minimum capacity (can't be less than this)
        int left = *max_element(weights.begin(), weights.end());

        // Calculate the sum of all package weights as maximum capacity (ship all at once)
        int right = accumulate(weights.begin(), weights.end(), 0);

        // Binary search loop to find optimal capacity between left and right
        while (left < right) {
            // Calculate mid value as potential capacity to test
            int mid = left + (right - left) / 2;

            // Calculate how many days needed if ship capacity is mid
            int needed = daysNeeded(weights, mid);

            // If days needed is less or equal to allowed days,
            // try to reduce capacity by moving right boundary
            if (needed <= d) {
                right = mid;
            } else {
                // If days needed is more than allowed, increase capacity by moving left boundary
                left = mid + 1;
            }
        }

        // Left is now the minimum capacity that can ship packages within d days
        return left;
    }
};


