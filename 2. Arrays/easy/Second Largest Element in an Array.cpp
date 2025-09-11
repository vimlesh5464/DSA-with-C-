//Second Largest Element in an Array
// C++ program to find second largest element in an array
// using Sorting

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//[Naive Approach] Using Sorting 

// Time Complexity: O(n*log(n)), as sorting the array takes O(n*log(n)) time and traversing
// the array can take O(n) time in the worst case, so total time complexity = (n*log(n) + n) = O(n*log(n)).
// Auxiliary space: O(1), as no extra space is required.
// function to find the second largest element
int getSecondLargest(vector<int> &arr) {
    int n = arr.size();
    
    // Sort the array in non-decreasing order
    sort(arr.begin(), arr.end());
  
    // start from second last element as last element is the largest
    for (int i = n - 2; i >= 0; i--) {
      
        // return the first element which is not equal to the 
        // largest element
        if (arr[i] != arr[n - 1]) {
            return arr[i];
        }
    }
  
    // If no second largest element was found, return -1
    return -1;
}

//[Better Approach] Two Pass Search 
// Time Complexity: O(2*n) = O(n), as we are traversing the array two times.
// Auxiliary space: O(1), as no extra space is required.
int getSecondLargest(vector<int> &arr) {
  int n = arr.size();

  int largest = -1, secondLargest = -1;

  // finding the largest element
  for (int i = 0; i < n; i++) {
      if (arr[i] > largest)
          largest = arr[i];
  }

  // finding the second largest element
  for (int i = 0; i < n; i++) {

      // Update second largest if the current element is greater
      // than second largest and not equal to the largest
      if (arr[i] > secondLargest && arr[i] != largest) {
          secondLargest = arr[i];
      }
  }
  return secondLargest;
}

// [Expected Approach] One Pass Search 
// Time Complexity: O(n), as we are traversing the array only once.
// Auxiliary space: O(1)

int getSecondLargest(vector<int> &arr) {
  int n = arr.size();

  int largest = -1, secondLargest = -1;

  // finding the second largest element
  for (int i = 0; i < n; i++) {

      // If arr[i] > largest, update second largest with
      // largest and largest with arr[i]
      if(arr[i] > largest) {
        secondLargest = largest;
          largest = arr[i];
      }
    
      // If arr[i] < largest and arr[i] > second largest, 
      // update second largest with arr[i]
      else if(arr[i] < largest && arr[i] > secondLargest) {
        secondLargest = arr[i];
      }
  }
  return secondLargest;
}
int main() {
    vector<int> arr = { 12, 35, 1, 10, 34, 1 };
    cout<<getSecondLargest(arr);
    return 0;
}