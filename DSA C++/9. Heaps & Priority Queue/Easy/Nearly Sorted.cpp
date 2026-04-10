// Given an array arr[], where each element is at most k positions away from its correct position in the sorted order.
// Your task is to restore the sorted order of arr[] by rearranging the elements in place.

// Note: Don't use any sort() method.

// Examples:

// Input: arr[] = [2, 3, 1, 4], k = 2
// Output: [1, 2, 3, 4]
// Explanation: All elements are at most k = 2 positions away from their correct positions.
// Element 1 moves from index 2 to 0
// Element 2 moves from index 0 to 1
// Element 3 moves from index 1 to 2
// Element 4 stays at index 3

// Input: arr[]= [7, 9, 14], k = 1
// Output: [7, 9, 14]
// Explanation: All elements are already stored in the sorted order.

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ k < arr.size()
// 1 ≤ arr[i] ≤ 106


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
  public:
      void nearlySorted(vector<int>& arr, int k) {
          int n = arr.size();
  
          for (int i = 1; i < n; i++) {
              int key = arr[i];
              int j = i - 1;
  
              // move only k range
              while (j >= 0 && j >= i - k && arr[j] > key) {
                  arr[j + 1] = arr[j];
                  j--;
              }
  
              arr[j + 1] = key;
          }
      }
  };

void nearlySorted(vector<int> &arr, int k) {

    int n = arr.size();

    // creating a min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // pushing first k elements in pq
    for (int i = 0; i < k; i++)
        pq.push(arr[i]);

    int i;

    for (i = k; i < n; i++) {

        pq.push(arr[i]);

        // size becomes k+1 so pop it
        // and add minimum element in (i-k) index
        arr[i - k] = pq.top();
        pq.pop();
    }

    // puting remaining elements in array
    while (!pq.empty()) {
        arr[i - k] = pq.top();
        pq.pop();
        i++;
    }
}

int main() {
    vector<int> arr = {2, 3, 1, 4};
    int k = 2;
    nearlySorted(arr, k);
    for (int x : arr)
        cout << x << ' ';
    return 0;
}