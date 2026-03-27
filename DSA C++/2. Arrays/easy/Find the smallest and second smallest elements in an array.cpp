// Given an array arr[] of integers, find the smallest and second smallest distinct elements in the array. The result should be returned in ascending order, meaning the smallest element should come first, followed by the second smallest. If there is no valid second smallest (i.e., all elements are the same or the array has fewer than two elements), then return -1.
// Smallest-and-2nd-smallest-elements-in-an-array

// Examples:

//     Input: arr[] = [12, 25, 8, 55, 10, 33, 17, 11]
//     Output: [8, 10]
//     Explanation: The smallest element is 1 and second smallest element is 10.

//     Input: arr[] = [2, 4, 3, 5, 6]
//     Output: [2, 3]
//     Explanation: 2 and 3 are respectively the smallest and second smallest elements in the array.

//     Input: arr[] = [1, 1, 1]
//     Output: [-1]
//     Explanation: Only element is 1 which is smallest, so there is no second smallest element.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//[Naive Approach] Using Sorting - O(n × log(n)) Time and O(1) Space

vector<int> minAnd2ndMin(vector<int> &arr) {
    
    // sort the array in ascending order
    sort(arr.begin(), arr.end());
    
    int n = arr.size();
    
    // initialize minimum and second minimum with 
    // smallest possible integer
    int mini = INT_MIN, secmini = INT_MIN;
    
    // the first element after sorting is the minimum
    mini = arr[0];
    
    // find the first element greater than mini 
    // (i.e., second minimum)
    for(int i = 0; i < n; i++) {
        
        if(arr[i] != mini) {
            secmini = arr[i];
            break;
        }
    }
    
    // if no second minimum found (i.e., all elements are equal)
    // return -1
    if(secmini == INT_MIN) {
        return {-1};
    }
    
    // return both minimum and second minimum
    return {mini, secmini};
}

//[Better Approach] Using Two Pass - O(n) Time and O(1) Space

vector<int> minAnd2ndMin(vector<int> &arr) {
    
  int n = arr.size();
  int mini = INT_MAX;      
  int secmini = INT_MAX;
  
  // First loop to find the minimum element in the array
  for(int i = 0; i < n; i++) {
      mini = min(mini, arr[i]);
  }

  // Second loop to find the second minimum element 
  for(int i = 0; i < n; i++) {
      if(arr[i] != mini) {
          secmini = min(secmini, arr[i]);
      }
  }

  // If second minimum was not updated, it means all elements are equal
  if(secmini == INT_MAX) {
      return {-1};  
  }

  return {mini, secmini};
}

//[Expected Approach] Using Single Pass - O(n) Time and O(1) Space

vector<int> minAnd2ndMin(const vector<int> &arr) {
    
  int n = arr.size();

  // Need at least two elements to have a second minimum
  if (n < 2) {
      return { -1 };
  }

  // Initialize first and second minimums to "infinity"
  int first = INT_MAX;
  int second = INT_MAX;

  // Single pass over the array
  for (int i = 0; i < n; i++) {
      
      // Found new minimum: shift down the old minimum
      if (arr[i] < first) {
          second = first;
          first = arr[i];
      }
      
      // arr[i] is not equal to first but smaller than current second
      else if (arr[i] < second && arr[i] != first) {
          second = arr[i];
      }
  }

  // If second was never updated, all elements were equal
  if (second == INT_MAX) {
      return { -1 };
  }

  // Return the two minima
  return { first, second };
}

int main() {
    vector<int> arr = {12, 25, 8, 55, 10, 33, 17, 11};
    vector<int> res = minAnd2ndMin(arr);
    for(auto it : res) {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}