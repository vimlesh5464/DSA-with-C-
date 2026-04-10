// Given an array arr[] containing both positive and negative integers, the task is to find the length of the longest subarray with a sum equals to 0.

// Note: A subarray is a contiguous part of an array, formed by selecting one or more consecutive elements while maintaining their original order.

// Examples:

// Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
// Output: 5
// Explanation: The longest subarray with sum equals to 0 is [-2, 2, -8, 1, 7].

// Input: arr[] = [2, 10, 4]
// Output: 0
// Explanation: There is no subarray with a sum of 0.

// Input: arr[] = [1, 0, -4, 3, 1, 0]
// Output: 5
// Explanation: The longest subarray with sum equals to 0 is [0, -4, 3, 1, 0]

// Constraints:
// 1 ≤ arr.size() ≤ 106
// −103 ≤ arr[i] ≤ 103
#include<unordered_map>
#include <iostream>
using namespace std;

int maxLen(vector<int>& arr) {
  int n = arr.size();
  int maxLen = 0;

  for (int i = 0; i < n; i++) {
      int sum = 0;

      for (int j = i; j < n; j++) {
          sum += arr[j];

          if (sum == 0) {
              maxLen = max(maxLen, j - i + 1);
          }
      }
  }

  return maxLen;
}

int maxLen(vector<int>& arr) {
  unordered_map<int, int> mp; // sum -> index
  int sum = 0;
  int maxLen = 0;

  for (int i = 0; i < arr.size(); i++) {
      sum += arr[i];

      // Case 1: sum == 0
      if (sum == 0) {
          maxLen = i + 1;
      }

      // Case 2: sum seen before
      if (mp.find(sum) != mp.end()) {
          maxLen = max(maxLen, i - mp[sum]);
      } else {
          // store first occurrence
          mp[sum] = i;
      }
  }

  return maxLen;
}