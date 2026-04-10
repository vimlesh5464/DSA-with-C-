
// Given an array arr[] of n integers and a target value, check if there exists a pair whose sum equals the target. This is a variation of the 2-Sum problem.

// Examples: 

//     Input: arr[] = [0, -1, 2, -3, 1], target = -2
//     Output: true
//     Explanation: There is a pair (1, -3) with the sum equal to given target, 1 + (-3) = -2.

//     Input: arr[] = [1, -2, 1, 0, 5], target = 0
//     Output: false
//     Explanation: There is no pair with sum equals to given target.


#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;

bool twoSum(vector<int> &arr, int target) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
      
        // For each element arr[i], check every
        // other element arr[j] that comes after it
        for (int j = i + 1; j < n; j++) {
          
            // Check if the sum of the current pair
            // equals the target
            if (arr[i] + arr[j] == target) {
                return true;
            }
        }
    }
  
    // If no pair is found after checking
    // all possibilities
    return false;
}

bool hasPair(vector<int>& arr, int target) {
  sort(arr.begin(), arr.end());

  int left = 0, right = arr.size() - 1;

  while (left < right) {
      int sum = arr[left] + arr[right];

      if (sum == target) return true;
      else if (sum < target) left++;
      else right--;
  }

  return false;
}


bool hasPair(vector<int>& arr, int target) {
  unordered_set<int> st;

  for (int x : arr) {
      if (st.find(target - x) != st.end()) {
          return true;
      }
      st.insert(x);
  }

  return false;
}