#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//Using Hash Set - Works for Unsorted Also - O(n) Time and O(n) Space
int removeDuplicates(vector<int>& arr) {
  
    // To track seen elements
    unordered_set<int> s; 
  
    // To maintain the new size of the array
    int idx = 0;  

    for (int i = 0; i < arr.size(); i++) {
        if (s.find(arr[i]) == s.end()) { 
            s.insert(arr[i]);  
            arr[idx++] = arr[i];  
        }
    }
 
    // Return the size of the array 
    // with unique elements
    return s.size(); 
}

//Expected Approach - O(n) Time and O(1) Space

int removeDuplicates(vector<int>& arr) {
  int n = arr.size();
  if (n <= 1)
      return n;

  // Start from the second element
  int idx = 1; 

  for (int i = 1; i < n; i++) {
      if (arr[i] != arr[i - 1]) {
          arr[idx++] = arr[i];
      }
  }
  return idx;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int newSize = removeDuplicates(arr);
    for (int i = 0; i < newSize; i++) 
        cout << arr[i] << " ";
    return 0;
}