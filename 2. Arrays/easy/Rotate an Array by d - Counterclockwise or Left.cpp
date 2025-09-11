
// C++ Program to left rotate the array by d positions
// by rotating one element at a time

#include <iostream>
#include <vector>
using namespace std;

////[Naive Approach] Rotate one by one - O(n * d) Time and O(1) Space
// Time Complexity: O(n*d), the outer loop runs d times, and within each iteration,
//  the inner loop shifts all n elements of the array by one position, resulting in a
//   total of n*d operations.
// Auxiliary Space: O(1)

// Function to left rotate array by d positions
void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();
  
    // Repeat the rotation d times
    for (int i = 0; i < d; i++) {
      
        // Left rotate the array by one position
        int first = arr[0];
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = first;
    }
}

//[Better Approach] Using Temporary Array - O(n) Time and O(n) Space
void rotateArr(vector<int>& arr, int d) {
  int n = arr.size();

  // Handle case when d > n
  d %= n;

  // Storing rotated version of array
  vector<int> temp(n);

  // Copy last n - d elements to the front of temp
  for (int i = 0; i < n - d; i++)
      temp[i] = arr[d + i];

  // Copy the first d elements to the back of temp
  for (int i = 0; i < d; i++)
      temp[n - d + i] = arr[i];

  // Copying the elements of temp in arr
  // to get the final rotated vector
  for (int i = 0; i < n; i++)
      arr[i] = temp[i];
}

//[Expected Approach 2] Using Reversal Algorithm - O(n) Time and O(1) Space
void rotateArr(vector<int>& arr, int d) {
  int n = arr.size();

  // Handle the case where d > size of array
  d %= n;

  // Reverse the first d elements
  reverse(arr.begin(), arr.begin() + d);

  // Reverse the remaining n-d elements
  reverse(arr.begin() + d, arr.end());

  // Reverse the entire array
  reverse(arr.begin(), arr.end());
}


int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    int d = 2;

    rotateArr(arr, d);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}