// Given an array, arr[] and an integer x, return true if there exists a pair of elements in the array whose absolute difference is x, otherwise, return false.

// Examples:

// Input: arr[] = [5, 20, 3, 2, 5, 80], x = 78
// Output: true
// Explanation: Pair (2, 80) have an absolute difference of 78.

// Input: arr[] = [90, 70, 20, 80, 50], x = 45
// Output: false
// Explanation: There is no pair with absolute difference of 45.

// Input: arr[] = [1], x = 1
// Output: false

// Constraints:
// 1<= arr.size() <=106 
// 1<= arr[i] <=106 
// 0<= x <=105



#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;
bool findPair(vector<int>& arr, int x) {
  int n = arr.size();

  for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
          if (abs(arr[i] - arr[j]) == x) {
              return true;
          }
      }
  }

  return false;
}

bool findPair(vector<int>& arr, int x) {
  unordered_set<int> st;

  for (int num : arr) {
      if (st.count(num + x) || st.count(num - x)) {
          return true;
      }
      st.insert(num);
  }

  return false;
}

bool findPair(vector<int>& arr, int x) {
  int n = arr.size();
  sort(arr.begin(), arr.end());

  int i = 0, j = 1;

  while (i < n && j < n) {
      if (i != j && abs(arr[j] - arr[i]) == x) {
          return true;
      }
      else if (abs(arr[j] - arr[i]) < x) {
          j++;
      }
      else {
          i++;
      }
  }

  return false;
}