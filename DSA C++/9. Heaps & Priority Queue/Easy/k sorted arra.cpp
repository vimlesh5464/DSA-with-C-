// Given an array of n distinct elements. Check whether the given array is a k-sorted 
//array or not. A k-sorted array is an array where each element is at most k distance
// away from its target position in the sorted array. 
// Return "Yes" if the array is a k-sorted array else return "No".

// Examples

// Input: n=6, arr[] = {3, 2, 1, 5, 6, 4}, k = 2
// Output: Yes
// Explanation: Every element is at most 2 distance away from its target position in thesorted array.  

// Input: n=7, arr[] = {13, 8, 10, 7, 15, 14, 12}, k = 1
// Output: No

// Expected Time Complexity: O(nlogn).
// Expected Auxiliary Space: O(n).

// Constraints:
// 1 ≤ n ≤ 105
// 0 ≤ k ≤ n
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

// User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
      vector<int> temp(arr, arr + n);
      sort(temp.begin(), temp.end());
      
      // store value -> index
      unordered_map<int, int> mp;
      for (int i = 0; i < n; i++) {
          mp[temp[i]] = i;
      }
      
      for (int i = 0; i < n; i++) {
          if (abs(i - mp[arr[i]]) > k)
              return "No";
      }
      
      return "Yes";
    }
};
class Solution {
  public:
      string isKSortedArray(int arr[], int n, int k) {
          
          // Step 1: Build sorted array using min-heap of size k+1
          priority_queue<int, vector<int>, greater<int>> pq;
          vector<int> sortedArr;
  
          for(int i = 0; i <= min(k, n-1); i++) {
              pq.push(arr[i]);
          }
  
          for(int i = k+1; i < n; i++) {
              sortedArr.push_back(pq.top());
              pq.pop();
              pq.push(arr[i]);
          }
  
          while(!pq.empty()) {
              sortedArr.push_back(pq.top());
              pq.pop();
          }
  
          // Step 2: Map value -> sorted index
          unordered_map<int, int> mp;
          for(int i = 0; i < n; i++) {
              mp[sortedArr[i]] = i;
          }
  
          // Step 3: Distance check
          for(int i = 0; i < n; i++) {
              if(abs(i - mp[arr[i]]) > k)
                  return "No";
          }
  
          return "Yes";
      }
  };

int main() {
  int arr[] = {3, 2, 1, 5, 6, 4};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = 2;

  Solution sol;
  cout << sol.isKSortedArray(arr, n, k) << endl; // Output: Yes

  int arr2[] = {13, 8, 10, 7, 15, 14, 12};
  int n2 = sizeof(arr2)/sizeof(arr2[0]);
  int k2 = 1;
  cout << sol.isKSortedArray(arr2, n2, k2) << endl; // Output: No

  return 0;
}
