// Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
// A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing. Return the maximum length of bitonic subsequence.
 
// Note : A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence

// Examples :

// Input: n = 5, nums[] = [1, 2, 5, 3, 2]
// Output: 5
// Explanation: The sequence [1, 2, 5] is increasing and the sequence [3, 2] is decreasing so merging both we will get length 5.

// Input: n = 8, nums[] = [1, 11, 2, 10, 4, 5, 2, 1]
// Output: 6
// Explanation: The bitonic sequence [1, 2, 10, 4, 2, 1] has length 6.

// Input: n = 3, nums[] = [10, 20, 30]
// Output: 0
// Explanation: The decreasing or increasing part cannot be empty.

// Input: n = 3, nums[] = [10, 10, 10]
// Output: 0
// Explanation: No strictly increasing or decreasing sequence exists.

// Constraints:
// 1 ≤ length of array ≤ 103
// 1 ≤ arr[i] ≤ 104


#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &arr) {

        vector<int> LIS_dp(n, 1);
        vector<int> LDS_dp(n, 1);

        int maxLen = 0;

        // LIS (left to right)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[j] < arr[i]) {
                    LIS_dp[i] = max(LIS_dp[i], LIS_dp[j] + 1);
                }
            }
        }

        // LDS (right to left)
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j > i; j--) {
                if(arr[j] < arr[i]) {
                    LDS_dp[i] = max(LDS_dp[i], LDS_dp[j] + 1);
                }
            }
        }

        for(int i = 0; i < n; i++) {

            if(LIS_dp[i] > 1 && LDS_dp[i] > 1) {
                maxLen = max(maxLen, LIS_dp[i] + LDS_dp[i] - 1);
            }
        }

        return maxLen;
    }
};
