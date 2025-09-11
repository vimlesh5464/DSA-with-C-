//[Naive Approach] Using Sorting - O(n * log n) time and O(1) space
// C++ program to find the third largest
// element in an array.
#include <iostream>
#include<vector>
using namespace std;

int thirdLargest(vector<int> &arr) {
    int n = arr.size();
    
    // Sort the array 
    sort(arr.begin(), arr.end());
    
    // Return the third largest element 
    return arr[n-3];
}

//[Expected Approach - 1] Using Three Loops - O(n) time and O(1) space

int thirdLargest(vector<int> &arr) {
  int n = arr.size();
  
  // Find the first maximum element.
  int first = INT_MIN;
  for (int i=0; i<n; i++) {
      if (arr[i] > first) first = arr[i];
  }
  
  // Find the second max element.
  int second = INT_MIN;
  for (int i=0; i<n; i++) {
      if (arr[i] > second && arr[i] < first) {
          second = arr[i];
      }
  }
  
  // Find the third largest element.
  int third = INT_MIN;
  for (int i=0; i<n; i++) {
      if (arr[i] > third && arr[i] < second) {
          third = arr[i];
      }
  }
  
  // Return the third largest element 
  return third;
}

//[Expected Approach - 2] Using Three variables - O(n) time and O(1) space
int thirdLargest(vector<int> &arr) {
  int n = arr.size();
  
  int first = INT_MIN, second = INT_MIN,
  third = INT_MIN;
  
  for (int i=0; i<n; i++) {
      
      // If arr[i] is greater than first,
      // set third to second, second to 
      // first and first to arr[i].
      if (arr[i] > first) {
          third = second;
          second = first;
          first = arr[i];
      }
      
      // If arr[i] is greater than second, 
      // set third to second and second 
      // to arr[i].
      else if (arr[i] > second) {
          third = second;
          second = arr[i];
      }
      
      // If arr[i] is greater than third,
      // set third to arr[i].
      else if (arr[i] > third) {
          third = arr[i];
      }
  }
  
  // Return the third largest element 
  return third;
}

int main() {
    vector<int> arr = {1, 14, 2, 16, 10, 20};
    cout << thirdLargest(arr) << endl;

    return 0;
}