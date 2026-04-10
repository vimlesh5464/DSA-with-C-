// You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

// Examples:

// Input: stalls[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at stalls[0], 
// the second cow can be placed at stalls[2] and 
// the third cow can be placed at stalls[3]. 
// The minimum distance between cows in this case is 3, which is the largest among all possible ways.

// Input: stalls[] = [10, 1, 2, 7, 5], k = 3
// Output: 4
// Explanation: The first cow can be placed at stalls[0],
// the second cow can be placed at stalls[1] and
// the third cow can be placed at stalls[4].
// The minimum distance between cows in this case is 4, which is the largest among all possible ways.

// Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
// Output: 1
// Explanation: There are 6 stalls and only 5 cows, we try to place the cows such that the minimum distance between any two cows is as large as possible.
// The minimum distance between cows in this case is 1, which is the largest among all possible ways.

// Constraints:
// 2 ≤ stalls.size() ≤ 106
// 0 ≤ stalls[i] ≤ 108
// 2 ≤ k ≤ stalls.size()


#include<iostream>
#include<vector>
#include <numeric>  
using namespace std;
// Class to solve the Aggressive Cows problem
class Solution {
public:
    // Function to check if we can place all cows with at least distance 'd'
    bool canPlace(vector<int>& stalls, int cows, int d) {
        // Place the first cow at the first stall
        int count = 1;
        int lastPos = stalls[0];

        // Try placing the remaining cows
        for (int i = 1; i < stalls.size(); i++) {
            // If current stall is at least 'd' away from last cow
            if (stalls[i] - lastPos >= d) {
                // Place a cow here
                count++;
                lastPos = stalls[i];
            }
            // If all cows placed successfully, return true
            if (count >= cows) return true;
        }
        // Not possible to place all cows
        return false;
    }

    // Function to find maximum minimum distance using brute force
    int aggressiveCows(vector<int>& stalls, int cows) {
        // Step 1: Sort stall positions
        sort(stalls.begin(), stalls.end());

        // Step 2: Get the maximum possible distance
        int n = stalls.size();
        int maxDist = stalls[n - 1] - stalls[0];

        // Step 3: Variable to store answer
        int ans = 0;

        // Step 4: Try all possible distances from 1 to maxDist
        for (int d = 1; d <= maxDist; d++) {
            // If cows can be placed with distance d
            if (canPlace(stalls, cows, d)) {
                // Update answer
                ans = d;
            }
        }
        // Step 5: Return the maximum valid distance
        return ans;
    }
};


// Class to solve Aggressive Cows problem
class Solution {
  public:
      // Function to check if we can place all cows with at least 'd' distance
      bool canPlace(vector<int>& stalls, int cows, int d) {
          // Place first cow at the first stall
          int count = 1;
          int lastPos = stalls[0];
  
          // Loop through all stalls
          for (int i = 1; i < stalls.size(); i++) {
              // Check if this stall is at least 'd' away from last placed cow
              if (stalls[i] - lastPos >= d) {
                  // Place the cow here
                  count++;
                  // Update last placed cow position
                  lastPos = stalls[i];
              }
              // If all cows are placed successfully
              if (count >= cows) return true;
          }
          // Return false if we could not place all cows
          return false;
      }
  
      // Function to maximize minimum distance between cows
      int aggressiveCows(vector<int>& stalls, int cows) {
          // Sort the stalls
          sort(stalls.begin(), stalls.end());
  
          // Define search space
          int low = 1;
          int high = stalls.back() - stalls.front();
          int ans = 0;
  
          // Apply binary search
          while (low <= high) {
              // Find mid distance
              int mid = low + (high - low) / 2;
  
              // If placing cows is possible with mid distance
              if (canPlace(stalls, cows, mid)) {
                  // Store this as potential answer
                  ans = mid;
                  // Try to find larger minimum distance
                  low = mid + 1;
              }
              else {
                  // Otherwise try smaller distance
                  high = mid - 1;
              }
          }
          // Return the largest minimum distance
          return ans;
      }
  };
  
// Driver code
int main() {
    // Example input
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;

    // Create object of Solution class
    Solution obj;
    // Call function and print result
    cout << obj.aggressiveCows(stalls, cows) << endl;

    return 0;
}
