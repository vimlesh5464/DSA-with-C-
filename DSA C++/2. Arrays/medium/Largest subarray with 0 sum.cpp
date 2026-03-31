// Given an array arr[] containing both positive and negative integers, 
//the task is to find the length of the longest subarray with a sum equals to 0.

// Note: A subarray is a contiguous part of an array, formed by selecting 
//one or more consecutive elements while maintaining their original order.

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
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int solveBruteForce(vector<int>& a) {
  int n = a.size();
  int maxLen = 0;

  for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
          sum += a[j];
          if (sum == 0) {
              maxLen = max(maxLen, j - i + 1);
          }
      }
  }

  return maxLen;
}


int solve(vector<int>& a) {
  int maxLen = 0;
  unordered_map<int, int> sumIndexMap;
  int sum = 0;

  for (int i = 0; i < a.size(); i++) {
      sum += a[i];

      if (sum == 0) {
          maxLen = i + 1;
      } else if (sumIndexMap.find(sum) != sumIndexMap.end()) {
          maxLen = max(maxLen, i - sumIndexMap[sum]);
      } else {
          sumIndexMap[sum] = i;
      }
  }

  return maxLen;
}



int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi; 
}


int main() {
  vector<int> a = {9, -3, 3, -1, 6, -5};
  cout << solve(a) << endl;

  return 0;
}


