#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
      int jump(vector<int>& nums) {
          int n = nums.size();
  
          if (n <= 1) return 0;
          if (nums[0] == 0) return -1;
  
          int jumps = 0;
          int currentEnd = 0;
          int farthest = 0;
  
          for (int i = 0; i < n - 1; i++) {
              farthest = max(farthest, i + nums[i]);
  
              // If we are stuck
              if (i == currentEnd) {
                  if (farthest == currentEnd)
                      return -1;
  
                  jumps++;
                  currentEnd = farthest;
              }
          }
  
          return jumps;
      }
  };
  
class Solution {
public:
    // Function to find the minimum number of jumps using brute-force recursion
    int jump(vector<int>& nums) {
        return minJumps(nums, 0);
    }

private:
    // Recursive function to explore all possible jump paths
    int minJumps(vector<int>& nums, int position) {
        // If we are already at or beyond the last index, no more jumps needed
        if (position >= nums.size() - 1) return 0;

        // If we can't move from current position
        if (nums[position] == 0) return INT_MAX;

        int minStep = INT_MAX;

        // Try every possible jump from 1 to nums[position]
        for (int jump = 1; jump <= nums[position]; ++jump) {
            int subResult = minJumps(nums, position + jump);

            // If the result is not INT_MAX, update minimum step
            if (subResult != INT_MAX)
                minStep = min(minStep, 1 + subResult);
        }

        return minStep;
    }
};
class Solution {
  public:
       // Function to compute the minimum number of jumps to reach the last index
      int jump(vector<int>& nums) {
          // Get the size of input array
          int n = nums.size();
  
          // Initialize DP array with large value
          vector<int> dp(n, INT_MAX);
  
          // It takes 0 jumps to reach the starting index
          dp[0] = 0;
  
          // Iterate through all indices
          for (int i = 0; i < n; ++i) {
              // For each position, calculate max jump
              for (int j = 1; j <= nums[i] && i + j < n; ++j) {
                  // Update dp value for the position we can reach
                  dp[i + j] = min(dp[i + j], dp[i] + 1);
              }
          }
  
          // Return the minimum jumps to reach last index
          return dp[n - 1];
      }
  };
// Driver Code
int main() {
    vector<int> nums = {2, 3, 1, 1, 4};

    Solution sol;
    cout << "Minimum number of jumps: " << sol.jump(nums) << endl;

    return 0;
}
