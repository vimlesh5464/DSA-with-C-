// Given an array arr[] and an integer diff, count the number of ways to
// partition the array into two subsets such that the difference between
// their sums is equal to diff.

// Note: A partition in the array means dividing an array into two subsets say S1 and S2 such that the union of S1 and S2 is equal to the original array and each element is present in only one of the subsets.

// Examples :

// Input: arr[] = [5, 2, 6, 4], diff = 3
// Output: 1
// Explanation: There is only one possible partition of this array. Partition : [6, 4], [5, 2]. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.

// Input: arr[] = [1, 1, 1, 1], diff = 0 
// Output: 6 
// Explanation: We can choose two 1's from indices [0,1], [0,2], [0,3], [1,2], [1,3], [2,3] and put them in sum1 and remaning two 1's in sum2.
// Thus there are total 6 ways for partition the array arr. 

// Input: arr[] = [3, 2, 7, 1], diff = 4  
// Output: 0
// Explanation: There is no possible partition of the array that satisfy the given difference. 

// Constraint:
// 1 ≤ arr.size() ≤ 50
// 0 ≤ diff ≤ 50
// 0 ≤ arr[i] ≤ 6
#include <iostream>
#include<vector>
#include <numeric>
using namespace std;

int solve(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
  if (i == 0) {
      if (target == 0 && arr[0] == 0) return 2; // special case
      if (target == 0 || target == arr[0]) return 1;
      return 0;
  }

  if (dp[i][target] != -1) return dp[i][target];

  int notTake = solve(i - 1, target, arr, dp);

  int take = 0;
  if (arr[i] <= target)
      take = solve(i - 1, target - arr[i], arr, dp);

  return dp[i][target] = take + notTake;
}

int countPartitions(vector<int>& arr, int diff) {
  int n = arr.size();
  int totalSum = 0;

  for (int x : arr) totalSum += x;

  if ((totalSum + diff) % 2 != 0) return 0;

  int target = (totalSum + diff) / 2;

  vector<vector<int>> dp(n, vector<int>(target + 1, -1));

  return solve(n - 1, target, arr, dp);
}

class Solution {
public:
    // Function to count partitions with given difference
    int countPartitions(vector<int>& arr, int d) {
        // Calculate total sum of array
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        // Check if solution is possible
        if ((totalSum + d) % 2 != 0 || d > totalSum) return 0;

        // Calculate target sum
        int K = (totalSum + d) / 2;

        // Create dp array of size K+1
        vector<int> dp(K + 1, 0);

        // Base case: empty set makes sum 0
        dp[0] = 1;

        // If first element <= K, mark it
        if (arr[0] <= K) dp[arr[0]] += 1;

        // Process remaining elements
        for (int i = 1; i < arr.size(); i++) {
            vector<int> curr(K + 1, 0);
            curr[0] = 1;

            for (int t = 0; t <= K; t++) {
                int notTake = dp[t];
                int take = 0;
                if (arr[i] <= t) {
                    take = dp[t - arr[i]];
                }
                curr[t] = take + notTake;
            }
            dp = curr;
        }
        return dp[K];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4};
    int d = 1;
    cout << sol.countPartitions(arr, d) << endl;
    return 0;
}
