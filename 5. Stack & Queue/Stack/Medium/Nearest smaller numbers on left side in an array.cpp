//Nearest smaller numbers on left side in an array
#include <iostream>
#include <vector>
#include<stack>
using namespace std;

//[Naive Approach] Using Nested Loops - O(n^2) Time and O(1) Space
vector<int> nearestSmallerToLeft(vector<int>& arr){
    int n = arr.size();
    vector<int> result(n, -1);

    // for each element, check all elements 
    // on the left
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                result[i] = arr[j];
                break;
            }
        }
    }
    return result;
}

//[Expected Approach] Stack-based Approach (Monotonic stack)
// Time Complexity: O(n), each element is pushed and popped at most once, so total stack operations are linear.
// Auxiliary Space: O(n), in the worst case (strictly increasing array) the stack may hold all n elements.
vector<int> nearestSmallerToLeft(vector<int>& arr) {
  int n = arr.size();
  vector<int> result(n, -1);

  // stack to keep track of elements
  stack<int> s;

  // traverse the array from left to right
  for (int i = 0; i < n; i++) {
      // pop elements from stack until a smaller 
      // element is found or stack becomes empty
      while (!s.empty() && s.top() >= arr[i]) {
          s.pop();
      }

      // if stack is not empty, top is nearest smaller
      if (!s.empty()) {
          result[i] = s.top();
      }

      // push current element to stack
      s.push(arr[i]);
  }
  return result;
}

int main() {
    vector<int> arr = {1, 5, 0, 3, 4, 5};
    vector<int> ans = nearestSmallerToLeft(arr);

    for (int x : ans) cout << x << " ";
    return 0;
}