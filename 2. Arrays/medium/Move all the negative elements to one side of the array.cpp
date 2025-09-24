// C++ program to Move all negative numbers
// to beginning and positive to end
#include <iostream>
#include<vector>
using namespace std;

//[Expected Approach - 1] Using Quick Sort Partition - O(n) time and O(1) space
vector<int> move(vector<int> &arr) {
    int j = 0;
    for (int i=0; i<arr.size(); i++) {
        
        // If negative number is present
        // swap it with arr[j]
        if (arr[i]<0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    
    return arr;
}

//[Expected Approach - 2] Using Two Pointer Method - O(n) time and O(1) space
vector<int> move(vector<int> &arr) {
  int left = 0, right = arr.size()-1;
  while (left<right) {
      
      // increment left while arr[left]
      // is negative
      while (left<right && arr[left]<0) {
          left++;
      }
      
      // decrement right while arr[right]
      // is positive
      while (right>left && arr[right]>0) {
          right--;
      }
      
      // swap the two values.
      if (right>left) {
          swap(arr[left], arr[right]);
          left++;
          right--;
      }
  }
  
  return arr;
}


int main() {
    vector<int> arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    vector<int> ans = move(arr);
    
    for (auto num: ans) {
        cout << num << " ";
    }
    cout<<endl;

    return 0;
}