//[Naive Approach] Using Temporary Array - O(n) Time and O(n) Space
#include <iostream>
#include <vector>

using namespace std;

void pushZerosToEnd(vector<int> &arr) {
    int n = arr.size();
    vector<int> temp(n);

    // to keep track of the index in temp[]
    int j = 0;

    // Copy non-zero elements to temp[]
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0)
            temp[j++] = arr[i];
    }

    // Fill remaining positions in temp[] with zeros
    while (j < n) {
        temp[j++] = 0;
    }

    // Copy all the elements from temp[] to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

//[Better Approach] Two Traversals 

// First Traversal: Shift non-zero elements

//     Traverse the array and maintain the count of non-zero elements. This count is 
//initialized with 0 and keeps track of where the next non-zero element should be placed in the array.
//     If the element is non-zero, place it at arr[count] and increment count by 1.
//     After traversing all the elements, all non-zero elements will be shifted to the front
// while maintaining their original order.

// Second Traversal: Fill remaining positions with zeros

//     After the first traversal, all non-zero elements will be at the start of the array and
// count will store the index where the first zero should be placed.
//     Iterate from count to the end of array and fill all indices with 0.

// Time Complexity: O(n), as we are traversing the array only twice.
// Auxiliary Space: O(1)
void pushZerosToEnd(vector<int>& arr) {
    
  // Count of non-zero elements
  int count = 0;  

  // If the element is non-zero, replace the element at
  // index 'count' with this element and increment count
  for (int i = 0; i < arr.size(); i++) {
      if (arr[i] != 0)
          arr[count++] = arr[i];
  }

  // Now all non-zero elements have been shifted to
  // the front. Make all elements 0 from count to end.
  while (count < arr.size())
      arr[count++] = 0;
}

//[Expected Approach] One Traversal 

// Time Complexity: O(n), as we are traversing the array only once.
// Auxiliary Space: O(1)
void pushZerosToEnd(vector<int>& arr) {
  
  // Pointer to track the position 
  // for next non-zero element
  int count = 0;
   
  for (int i = 0; i < arr.size(); i++) {

      // If the current element is non-zero
      if (arr[i] != 0) {
        
          // Swap the current element with 
          // the 0 at index 'count'
          swap(arr[i], arr[count]);
          // Move 'count' pointer to the 
          // next position
          count++;
      }
  }
}

int main() {
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd(arr);

    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}