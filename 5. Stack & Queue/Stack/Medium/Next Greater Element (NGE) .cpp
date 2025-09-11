//Next Greater Element (NGE) for every element in given Array
#include <iostream>
#include <vector>
#include<stack>
using namespace std;

//[Naive Approach] Using Nested Loops - O(n^2) Time and O(1) Space

// The idea is to look at all the elements to its right and check if 
// there's a larger element for each element in the array. If we find one,
//  we store it as the next greater element. If no greater element is found,
//   we store -1. This is done using two nested loops: the outer loop goes 
//   through each element, and the inner loop searches the rest of the array for a greater element.

vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, -1);

    // iterate through each element in the array
    for (int i = 0; i < n; i++) {

        // check for the next greater element
        // in the rest of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                res[i] = arr[j];
                break;
            }
        }
    }

    return res;
}

//[Expected Approach] Using Stack - O(n) Time and O(n) Space
// The idea is to use stack to find the next greater element by using the Last-In-First-Out (LIFO) property.
//  We traverse the array from right to left. For each element, we remove elements from the stack that are
//   smaller than or equal to it, as they cannot be the next greater element. If the stack is not empty 
//   after this, the top element of the stack is the next greater element for the current element.
//    We then push the current element onto the stack. 

vector<int> nextLargerElement(vector<int> &arr) {
  int n = arr.size();
  vector<int> res(n, -1);
  stack<int> stk;

  for (int i = n - 1; i >= 0; i--) {

      // Pop elements from the stack that are less
      // than or equal to the current element
      while (!stk.empty() && stk.top() <= arr[i]) {
          stk.pop();
      }

      // If the stack is not empty, the top element
      // is the next greater element
      if (!stk.empty()) {
          res[i] = stk.top();
      }

      // Push the current element onto the stack
      stk.push(arr[i]);
  }

  return res;
}
int main() {

    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> res = nextLargerElement(arr);
    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}